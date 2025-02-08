/* This file was automatically generated by CasADi 3.6.7+.
 *  It consists of: 
 *   1) content generated by CasADi runtime: not copyrighted
 *   2) template code copied from CasADi source: permissively licensed (MIT-0)
 *   3) user code: owned by the user
 *
 */
#ifdef __cplusplus
extern "C" {
#endif

#ifndef casadi_real
#define casadi_real double
#endif

#ifndef casadi_int
#define casadi_int long long int
#endif

int opti_func(const casadi_real** arg, casadi_real** res, casadi_int* iw, casadi_real* w, int mem);
int opti_func_alloc_mem(void);
int opti_func_init_mem(int mem);
void opti_func_free_mem(int mem);
int opti_func_checkout(void);
void opti_func_release(int mem);
void opti_func_incref(void);
void opti_func_decref(void);
casadi_int opti_func_n_in(void);
casadi_int opti_func_n_out(void);
casadi_real opti_func_default_in(casadi_int i);
const char* opti_func_name_in(casadi_int i);
const char* opti_func_name_out(casadi_int i);
const casadi_int* opti_func_sparsity_in(casadi_int i);
const casadi_int* opti_func_sparsity_out(casadi_int i);
int opti_func_work(casadi_int *sz_arg, casadi_int* sz_res, casadi_int *sz_iw, casadi_int *sz_w);
int opti_func_work_bytes(casadi_int *sz_arg, casadi_int* sz_res, casadi_int *sz_iw, casadi_int *sz_w);
#define opti_func_SZ_ARG 315
#define opti_func_SZ_RES 316
#define opti_func_SZ_IW 3403
#define opti_func_SZ_W 40843
#ifdef __cplusplus
} /* extern "C" */
#endif
