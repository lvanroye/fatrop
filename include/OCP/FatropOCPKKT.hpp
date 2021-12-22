/**
 * @file FatropOCPKKT.hpp
 * @author your name (you@domain.com)
 * @brief this file contains classes to represent a KKT matrix by blasfeo submatrices 
 * @version 0.1
 * @date 2021-11-10
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef FATROP_OCP_KKT_INCLUDED
#define FATROP_OCP_KKT_INCLUDED
#include "../BLASFEO_WRAPPER/FatropLinearAlgebraBlasfeo.hpp"
#include "FatropOCP.hpp"
#include "../AUX/FatropAux.hpp"
#include "../AUX/FatropVector.hpp"
using namespace std;
namespace fatrop
{
    /** \brief this class contains all information to represent the KKT system of an equality constrained OCP*/
    class OCP_KKT
    {
    public:
        OCP_KKT(const OCP_dims &dims, fatrop_memory_allocator &fma) : K(dims.K), nu(dims.K, dims.nu, fma), nx(dims.K, dims.nx, fma), ng(dims.K, dims.ng, fma), RSQrqt(dims.nu + dims.nx + 1, dims.nu + dims.nx, dims.K, fma), BAbt(dims.nu + dims.nx + 1, dims.nx, dims.K, fma), Ggt(dims.nu + dims.nx + 1, dims.ng, dims.K, fma), aux(dims, fma){};
        int K;
        fatrop_memory_el<int> nu;
        fatrop_memory_el<int> nx;
        fatrop_memory_el<int> ng;
        /// small-scale Hessian
        fatrop_memory_matrix_bf RSQrqt;
        /// small-scale Jacobian dynamics
        fatrop_memory_matrix_bf BAbt;
        /// small-scale Jacobian stagewise eq constraints
        fatrop_memory_matrix_bf Ggt;
        class OCP_aux
        {
        public:
            OCP_aux(const OCP_dims &dims, fatrop_memory_allocator &fma) : ux_offs(dims.K, offsets(dims.nx + dims.nu), fma), g_offs(dims.K, offsets(dims.ng), fma), max_nu(max(dims.nu)), max_nx(max(dims.nx)), max_ng(max(dims.ng)){};
            /// offset arrays are used for efficiency
            const fatrop_memory_el<int> ux_offs;
            /// offset arrays are used for efficiency
            const fatrop_memory_el<int> g_offs;
            int max_nu;
            int max_nx;
            int max_ng;
        };
        OCP_aux aux;
    };
    class OCP_KKT_solver
    {
    public:
        OCP_KKT_solver(const OCP_dims &dims, fatrop_memory_allocator &fma) : Ppt(dims.nx + 1, dims.nx, dims.K, fma),
                                                                             Hh(vector<int>(1, max(dims.nx)), vector<int>(1, max(dims.nx + 1)), 1, fma), // the number of eqs can never exceed nx
                                                                             AL(vector<int>(1, max(dims.nu + dims.nx + 1)), vector<int>(1, max(dims.nx)), 1, fma),
                                                                             RSQrqt_tilde(dims.nu + dims.nx + 1, dims.nx + dims.nu, dims.K, fma),
                                                                             Ggt_stripe(vector<int>(1, max(dims.nu + dims.nx + 1)), vector<int>(1, max(dims.nx)), 1, fma),
                                                                             Ggt_tilde(dims.nu + dims.nx + 1, dims.nx, dims.K, fma),
                                                                             GgLt(vector<int>(1, max(dims.nu + dims.nx + 1)), vector<int>(1, max(dims.nu + dims.nx)), 1, fma),
                                                                             RSQrqt_hat(vector<int>(1, max(dims.nu + dims.nx + 1)), vector<int>(1, max(dims.nx + dims.nu)), 1, fma),
                                                                             Llt(dims.nu + dims.nx + 1, dims.nu + dims.nx, dims.K, fma),
                                                                             Llt_shift(vector<int>(1, max(dims.nu + dims.nx + 1)), vector<int>(1, max(dims.nx)), 1, fma),
                                                                             PpIt_tilde(vector<int>(1, dims.nx.at(0) + 1), vector<int>(1, dims.nx.at(0)), 1, fma),
                                                                             GgIt_tilde(vector<int>(1, dims.nx.at(0) + 1), vector<int>(1, dims.nx.at(0)), 1, fma),
                                                                             GgLIt(vector<int>(1, dims.nx.at(0) + 1), vector<int>(1, dims.nx.at(0)), 1, fma),
                                                                             HhIt(vector<int>(1, dims.nx.at(0) + 1), vector<int>(1, dims.nx.at(0)), 1, fma),
                                                                             PpIt_hat(vector<int>(1, dims.nx.at(0) + 1), vector<int>(1, dims.nx.at(0)), 1, fma),
                                                                             LlIt(vector<int>(1, dims.nx.at(0) + 1), vector<int>(1, dims.nx.at(0)), 1, fma),
                                                                             Pl(max(dims.nx), dims.K, fma), // number of equations can never exceed nx
                                                                             Pr(max(dims.nu), dims.K, fma),
                                                                             PlI(dims.nx.at(0), 1, fma),
                                                                             PrI(dims.nx.at(0), 1, fma),
                                                                             gamma(dims.K, vector<int>(dims.K, 0), fma),
                                                                             rho(dims.K, vector<int>(dims.K, 0), fma){};
        // solve a KKT system
        void fact_solve(OCP_KKT *OCP, const fatrop_vector_bf &ux, const fatrop_vector_bf &lam)
        {
            // define compiler macros for notational convenience
#define OCPMACRO(type, name, suffix) type name##suffix = ((type)OCP->name)
#define AUXMACRO(type, name, suffix) type name##suffix = ((type)OCP->aux.name)
#define SOLVERMACRO(type, name, suffix) type name##suffix = ((type)name)
            int K = OCP->K;
            // make variables local for efficiency
            OCPMACRO(MAT *, RSQrqt, _p);
            OCPMACRO(MAT *, BAbt, _p);
            OCPMACRO(MAT *, Ggt, _p);
            SOLVERMACRO(MAT *, Ppt, _p);
            SOLVERMACRO(MAT *, Hh, _p);
            SOLVERMACRO(MAT *, AL, _p);
            SOLVERMACRO(MAT *, RSQrqt_tilde, _p);
            SOLVERMACRO(MAT *, Ggt_stripe, _p);
            SOLVERMACRO(MAT *, Ggt_tilde, _p);
            SOLVERMACRO(PMAT *, Pl, _p);
            SOLVERMACRO(PMAT *, Pr, _p);
            SOLVERMACRO(MAT *, GgLt, _p);
            SOLVERMACRO(MAT *, RSQrqt_hat, _p);
            SOLVERMACRO(MAT *, Llt, _p);
            SOLVERMACRO(MAT *, Llt_shift, _p);
            SOLVERMACRO(MAT *, PpIt_tilde, _p);
            SOLVERMACRO(MAT *, GgIt_tilde, _p);
            SOLVERMACRO(MAT *, GgLIt, _p);
            SOLVERMACRO(MAT *, HhIt, _p);
            SOLVERMACRO(MAT *, PpIt_hat, _p);
            SOLVERMACRO(MAT *, LlIt, _p);
            SOLVERMACRO(PMAT *, PlI, _p);
            SOLVERMACRO(PMAT *, PrI, _p);
            SOLVERMACRO(VEC *, ux, _p);
            SOLVERMACRO(VEC *, lam, _p);
            // AUXMACRO(int, max_nu, );
            // AUXMACRO(int, max_nx, );
            // AUXMACRO(int, max_ng, );
            // AUXMACRO(int *, ux_offs, _p);
            // AUXMACRO(int *, g_offs, _p);
            OCPMACRO(int *, nu, _p);
            OCPMACRO(int *, nx, _p);
            OCPMACRO(int *, ng, _p);
            SOLVERMACRO(int *, gamma, _p);
            SOLVERMACRO(int *, rho, _p);
            MAT *RSQrq_hat_curr_p;
            int rank_k;

            /////////////// recursion ///////////////

            // last stage
            {
                const int nx = nx_p[K - 1];
                const int nu = nu_p[K - 1]; // this should be zero but is included here in case of misuse
                const int ng = ng_p[K - 1];
                // Pp_Km1 <- Qq_Km1
                GECP(nx + 1, nx, RSQrqt_p + (K - 1), nu, nu, Ppt_p + K - 1, 0, 0);
                // Hh_Km1 <- Gg_Km1
                GETR(nx + 1, ng, Ggt_p + (K - 1), nu, 0, Hh_p, 0, 0);
                gamma_p[K - 1] = ng;
                rho_p[K - 1] = 0;
            }
            for (int k = K - 2; k >= 0; --k)
            {
                const int nu = nu_p[k];
                const int nx = nx_p[k];
                const int nxp1 = nx_p[k + 1];
                const int ng = ng_p[k];
                // calculate the size of H_{k+1} matrix
                const int Hp1_size = gamma_p[k + 1] - rho_p[k + 1];
                // gamma_k <- number of eqs represented by Ggt_stripe
                const int gamma_k = Hp1_size + ng;
                //////// SUBSDYN
                {
                    // AL <- [BAb]^T_k P_kp1
                    GEMM_NT(nu + nx + 1, nx, nxp1, 1.0, BAbt_p + k, 0, 0, Ppt_p + k + 1, 0, 0, 0.0, AL_p, 0, 0, AL_p, 0, 0);
                    // AL[-1,:] <- AL[-1,:] + p_kp1^T
                    GEAD(1, nx, 1.0, Ppt_p + (k + 1), nx, 0, AL_p, nx + nu, 0);
                    // RSQrqt_stripe <- AL[BA] + RSQrqt
                    SYRK_LN_MN(nu + nx + 1, nu + nx, nxp1, 1.0, AL_p, 0, 0, BAbt_p + k, 0, 0, 1.0, RSQrqt_p + k, 0, 0, RSQrqt_tilde_p + k, 0, 0);
                    gamma_p[k] = gamma_k;
                    // if ng[k]>0
                    if (gamma_k > 0)
                    {
                        // if Gk nonempty
                        if (ng > 0)
                        {
                            // Ggt_stripe  <- Ggt_k
                            GECP(nu + nx + 1, ng, Ggt_p + k, 0, 0, Ggt_stripe_p, 0, Hp1_size);
                        }
                        // if Hkp1 nonempty
                        if (Hp1_size > 0)
                        {
                            // Ggt_stripe <- [Ggt_k [BAb_k^T]H_kp1]
                            GEMM_NT(nu + nx + 1, Hp1_size, nxp1, 1.0, BAbt_p + k, 0, 0, Hh_p, 0, 0, 0.0, Ggt_stripe_p, 0, 0, Ggt_stripe_p, 0, 0);
                            // Ggt_stripe[-1,ng:] <- Ggt_stripe[-1,ng:] + h_kp1^T
                            GEADTR(1, Hp1_size, 1.0, Hh_p, 0, nx, Ggt_stripe_p, nu + nx, 0);
                        }
                    }
                    else
                    {
                        rho_p[k] = 0;
                        rank_k = 0;
                        RSQrq_hat_curr_p = RSQrqt_tilde_p + k;
                    }
                }
                //////// TRANSFORM_AND_SUBSEQ
                {
                    // symmetric transformation, done a little different than in paper, in order to fuse LA operations
                    // LU_FACT_TRANSPOSE(Ggtstripe[:gamma_k, nu+nx+1], nu max)
                    LU_FACT_transposed(gamma_k, nu + nx + 1, nu, rank_k, Ggt_stripe_p, Pl_p + k, Pr_p + k);
                    rho_p[k] = rank_k;
                    if (gamma_k - rank_k > 0)
                    {
                        // transfer eq's to next stage
                        GETR(nx + 1, gamma_k - rank_k, Ggt_stripe_p, nu, rank_k, Hh_p, 0, 0);
                    }
                    rho_p[k] = rank_k;
                    if (rank_k > 0)
                    {
                        // Ggt_tilde_k <- Ggt_stripe[rho_k:nu+nx+1, :rho] L-T (note that this is slightly different from the implementation)
                        TRSM_RLNN(nu - rank_k + nx + 1, rank_k, -1.0, Ggt_stripe_p, 0, 0, Ggt_stripe_p, rank_k, 0, Ggt_tilde_p + k, 0, 0);
                        // permutations
                        TRTR_L(nu + nx, RSQrqt_tilde_p + k, 0, 0, RSQrqt_tilde_p + k, 0, 0); // copy lower part of RSQ to upper part
                        (Pr_p + k)->PM(rank_k, RSQrqt_tilde_p + k);                          //TODO make use of symmetry
                        (Pr_p + k)->MPt(rank_k, RSQrqt_tilde_p + k);
                        // GL <- Ggt_tilde_k @ RSQ[:rho,:nu+nx] + RSQrqt[rho:nu+nx+1, rho:] (with RSQ[:rho,:nu+nx] = RSQrqt[:nu+nx,:rho]^T)
                        GEMM_NT(nu - rank_k + nx + 1, nu + nx, rank_k, 1.0, Ggt_tilde_p + k, 0, 0, RSQrqt_tilde_p + k, 0, 0, 1.0, RSQrqt_tilde_p + k, rank_k, 0, GgLt_p, 0, 0);
                        // RSQrqt_hat = GgLt[nu-rank_k + nx +1, :rank_k] * G[:rank_k, :nu+nx] + GgLt[rank_k:, :]  (with G[:rank_k,:nu+nx] = Gt[:nu+nx,:rank_k]^T)
                        SYRK_LN_MN(nu - rank_k + nx + 1, nu + nx - rank_k, rank_k, 1.0, GgLt_p, 0, 0, Ggt_tilde_p + k, 0, 0, 1.0, GgLt_p, 0, rank_k, RSQrqt_hat_p, 0, 0);
                        RSQrq_hat_curr_p = RSQrqt_hat_p;
                    }
                    else
                    {
                        RSQrq_hat_curr_p = RSQrqt_tilde_p + k;
                    }
                }
                //////// SCHUR
                {
                    if (nu - rank_k > 0)
                    {
                        // DLlt_k = [chol(R_hatk); Llk@chol(R_hatk)^-T]
                        POTRF_L_MN(nu - rank_k + nx + 1, nu - rank_k, RSQrq_hat_curr_p, 0, 0, Llt_p + k, 0, 0);
                        // Pp_k = Qq_hatk - L_k^T @ Ll_k
                        // SYRK_LN_MN(nx+1, nx, nu-rank_k, -1.0,Llt_p+k, nu-rank_k,0, Llt_p+k, nu-rank_k,0, 1.0, RSQrq_hat_curr_p, nu-rank_k, nu-rank_k,Pp+k,0,0); // feature not implmented yet
                        GECP(nx + 1, nx, Llt_p + k, nu - rank_k, 0, Llt_shift_p, 0, 0); // needless operation because feature not implemented yet
                        SYRK_LN_MN(nx + 1, nx, nu - rank_k, -1.0, Llt_shift_p, 0, 0, Llt_shift_p, 0, 0, 1.0, RSQrq_hat_curr_p, nu - rank_k, nu - rank_k, Ppt_p + k, 0, 0);
                    }
                    else
                    {
                        GECP(nx + 1, nx, RSQrq_hat_curr_p, 0, 0, Ppt_p + k, 0, 0);
                    }
                    TRTR_L(nx, Ppt_p + k, 0, 0, Ppt_p + k, 0, 0);
                }
            }
            int rankI = 0;
            //////// FIRST_STAGE
            {
                const int nx = nx_p[0];
                int gamma_I = gamma_p[0] - rho_p[0];
                if (gamma_I > 0)
                {
                    GETR(nx, nx + 1, Hh_p, 0, 0, HhIt_p, 0, 0); // transposition may be avoided
                    LU_FACT_transposed(gamma_I, nx + 1, nx, rankI, HhIt_p, PlI_p, PrI_p);
#if DEBUG
                    assert(gamma_I == rankI);
#endif
                    // PpIt_tilde <- Ggt[rankI:nx+1, :rankI] L-T (note that this is slightly different from the implementation)
                    TRSM_RLNN(nx - rankI + 1, rankI, -1.0, HhIt_p, 0, 0, HhIt_p, rankI, 0, GgIt_tilde_p, 0, 0);
                    // permutations
                    (PrI_p)->PM(rankI, Ppt_p); //TODO make use of symmetry
                    (PrI_p)->MPt(rankI, Ppt_p);
                    // // GL <- GgIt_tilde @ Pp[:rankI,:nx] + Ppt[rankI:nx+1, rankI:] (with Pp[:rankI,:nx] = Ppt[:nx,:rankI]^T)
                    GEMM_NT(nx - rankI + 1, nx, rankI, 1.0, GgIt_tilde_p, 0, 0, Ppt_p, 0, 0, 1.0, Ppt_p, rankI, 0, GgLIt_p, 0, 0);
                    // // RSQrqt_hat = GgLt[nu-rank_k + nx +1, :rank_k] * G[:rank_k, :nu+nx] + GgLt[rank_k:, :]  (with G[:rank_k,:nu+nx] = Gt[:nu+nx,:rank_k]^T)
                    SYRK_LN_MN(nx - rankI + 1, nx - rankI, rankI, 1.0, GgLIt_p, 0, 0, GgIt_tilde_p, 0, 0, 1.0, GgLIt_p, 0, rankI, PpIt_hat_p, 0, 0);
                    // TODO skipped if nx-rankI = 0
                    POTRF_L_MN(nx - rankI + 1, nx - rankI, PpIt_hat_p, 0, 0, LlIt_p, 0, 0);
                }
                else
                {
                    rankI = 0;
                    POTRF_L_MN(nx + 1, nx, Ppt_p, 0, 0, LlIt_p, 0, 0);
                }
            }
            ////// FORWARD_SUBSTITUTION:
            // first stage
            {
                const int nx = nx_p[0];
                const int nu = nu_p[0];
                int gamma_I = gamma_p[0] - rho_p[0];
                // calculate xIb
                ROWEX(nx - rankI, -1.0, LlIt_p, nx - rankI, 0, ux_p, nu + rankI);
                // assume TRSV_LTN allows aliasing, this is the case in normal BLAS
                TRSV_LTN(nx - rankI, LlIt_p, 0, 0, ux_p, nu + rankI, ux_p, nu + rankI);
                // calculate xIa
                ROWEX(rankI, 1.0, GgIt_tilde_p, nx - rankI, 0, ux_p, nu);
                // assume aliasing is possible for last two elements
                GEMV_T(nx - rankI, rankI, 1.0, GgIt_tilde_p, 0, 0, ux_p, nu + rankI, 1.0, ux_p, nu, ux_p, nu);
                //// lag
                ROWEX(rankI, -1.0, Ppt_p, nx, 0, lam_p, 0);
                // assume aliasing is possible for last two elements
                GEMV_T(nx, rankI, -1.0, Ppt_p, 0, 0, ux_p, nu, 1.0, lam_p, 0, lam_p, 0);
                // U^-T
                TRSV_LNN(rankI, HhIt_p, 0, 0, lam_p, 0, lam_p, 0);
                // L^-T
                TRSV_UNU(rankI, HhIt_p, 0, 0, lam_p, 0, lam_p, 0);
                /// TODO!
                /// TODO!
                /// TODO!
                /// TODO!
                /// TODO!
                /// TODO!
                /// TODO!
                /// TODO!
                /// TODO!

                (PrI_p)->PtV(rankI, ux_p, nu);
            }
            int *offs_ux = (int *)OCP->aux.ux_offs;
            // other stages
            // for (int k = 0; k < K - 1; k++)
            for (int k = 0; k < K - 1; k++)
            {
                const int nx = nx_p[k];
                const int nu = nu_p[k];
                const int offs = offs_ux[k];
                const int rho_k = rho_p[k];
                const int numrho_k = nu - rho_k;
                if (numrho_k)
                {
                    /// calculate ukb_tilde
                    // -Lkxk - lk
                    ROWEX(numrho_k, -1.0, Llt_p + k, numrho_k + nx, 0, ux_p, offs + rho_k);
                    // assume aliasing of last two eliments is allowed
                    GEMV_T(nx, numrho_k, -1.0, Llt_p + k, numrho_k, 0, ux_p, offs + nu, 1.0, ux_p, offs + rho_k, ux_p, offs + rho_k);
                    TRSV_LTN(numrho_k, Llt_p + k, 0, 0, ux_p, offs + rho_k, ux_p, offs + rho_k);
                }
                /// calcualate uka_tilde
                if (rho_k > 0)
                {
                    ROWEX(rho_k, 1.0, Ggt_tilde_p + k, numrho_k + nx, 0, ux_p, offs);
                    GEMV_T(nx + numrho_k, rho_k, 1.0, Ggt_tilde_p + k, 0, 0, ux_p, offs + rho_k, 1.0, ux_p, offs, ux_p, offs);
                    (Pr_p + k)->PtV(rho_k, ux_p, offs);
                }
                // calculate xkp1
                const int nxp1 = nx_p[k + 1];
                const int nup1 = nu_p[k + 1];
                const int offsp1 = offs_ux[k + 1];
                ROWEX(nx, 1.0, BAbt_p + k, nu + nx, 0, ux_p, offsp1 + nup1);
                GEMV_T(nu + nx, nxp1, 1.0, BAbt_p + k, 0, 0, ux_p, offs, 1.0, ux_p, offsp1 + nup1, ux_p, offsp1 + nup1);
            }
            return;
        }
        fatrop_memory_matrix_bf Ppt;
        fatrop_memory_matrix_bf Hh;
        fatrop_memory_matrix_bf AL;
        fatrop_memory_matrix_bf RSQrqt_tilde;
        fatrop_memory_matrix_bf Ggt_stripe;
        fatrop_memory_matrix_bf Ggt_tilde;
        fatrop_memory_matrix_bf GgLt;
        fatrop_memory_matrix_bf RSQrqt_hat;
        fatrop_memory_matrix_bf Llt;
        fatrop_memory_matrix_bf Llt_shift; // needed because feature not implemented yet
        fatrop_memory_matrix_bf PpIt_tilde;
        fatrop_memory_matrix_bf GgIt_tilde;
        fatrop_memory_matrix_bf GgLIt;
        fatrop_memory_matrix_bf HhIt;
        fatrop_memory_matrix_bf PpIt_hat;
        fatrop_memory_matrix_bf LlIt;
        fatrop_memory_permutation_matrix Pl;
        fatrop_memory_permutation_matrix Pr;
        fatrop_memory_permutation_matrix PlI;
        fatrop_memory_permutation_matrix PrI;
        fatrop_memory_el<int> gamma;
        fatrop_memory_el<int> rho;
    };
} // namespace fatrop
#endif // FATROP_OCP_KKT_INCLUDED