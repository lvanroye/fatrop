//
// Copyright (C) 2024 Lander Vanroye, KU Leuven
//

#ifndef __fatrop_ip_algorithm_ip_nlp_orig_hxx__
#define __fatrop_ip_algorithm_ip_nlp_orig_hxx__
#include "fatrop/nlp/dims.hpp"
#include "ip_nlp_orig.hpp"
#include <cmath>

namespace fatrop
{

    template <typename ProblemType>
    IpNlpOrig<ProblemType>::IpNlpOrig(const NlpSp &nlp)
        : nlp_(nlp), modified_bounds_lower_(nlp_->nlp_dims().number_of_ineq_constraints),
          modified_bounds_upper_(nlp_->nlp_dims().number_of_ineq_constraints)
    {
    }

    template <typename ProblemType> const NlpDims &IpNlpOrig<ProblemType>::nlp_dims() const
    {
        return nlp_->nlp_dims();
    }

    template <typename ProblemType>
    const ProblemDims<ProblemType> &IpNlpOrig<ProblemType>::problem_dims() const
    {
        return nlp_->problem_dims();
    }

    template <typename ProblemType>
    Index IpNlpOrig<ProblemType>::eval_lag_hess(const ProblemInfo<ProblemType> &info,
                                                const Scalar objective_scale,
                                                const VecRealView &primal_x,
                                                const VecRealView &primal_s, const VecRealView &lam,
                                                Hessian<ProblemType> &hess)
    {
        return nlp_->eval_lag_hess(info, objective_scale, primal_x, primal_s, lam, hess);
    }

    template <typename ProblemType>
    Index IpNlpOrig<ProblemType>::eval_constr_jac(const ProblemInfo<ProblemType> &info,
                                                  const VecRealView &primal_x,
                                                  const VecRealView &primal_s,
                                                  Jacobian<ProblemType> &jac)
    {
        return nlp_->eval_constr_jac(info, primal_x, primal_s, jac);
    }

    template <typename ProblemType>
    Index IpNlpOrig<ProblemType>::eval_constraint_violation(const ProblemInfo<ProblemType> &info,
                                                            const VecRealView &primal_x,
                                                            const VecRealView &primal_s,
                                                            VecRealView &res)
    {
        return nlp_->eval_constraint_violation(info, primal_x, primal_s, res);
    }

    template <typename ProblemType>
    Index IpNlpOrig<ProblemType>::eval_objective_gradient(const ProblemInfo<ProblemType> &info,
                                                          const Scalar objective_scale,
                                                          const VecRealView &primal_x,
                                                          VecRealView &grad_x, VecRealView &grad_s)
    {
        return nlp_->eval_objective_gradient(info, objective_scale, primal_x, grad_x, grad_s);
    }

    template <typename ProblemType>
    Index IpNlpOrig<ProblemType>::eval_objective(const ProblemInfo<ProblemType> &info,
                                                 const Scalar objective_scale,
                                                 const VecRealView &primal_x,
                                                 const VecRealView &primal_s, Scalar &res)
    {
        return nlp_->eval_objective(info, objective_scale, primal_x, primal_s, res);
    }

    template <typename ProblemType>
    Index IpNlpOrig<ProblemType>::get_bounds(const ProblemInfo<ProblemType> &info,
                                             VecRealView &lower_bounds, VecRealView &upper_bounds)
    {
        const Index number_of_slacks = nlp_->nlp_dims().number_of_ineq_constraints;
        nlp_->get_bounds(info, modified_bounds_lower_, modified_bounds_upper_);
        auto lower_bounded = [&](const Index i) { return !std::isinf(modified_bounds_lower_(i)); };
        auto upper_bounded = [&](const Index i) { return !std::isinf(modified_bounds_upper_(i)); };
        auto updated_lower = modified_bounds_lower_ -
                             min(VecRealScalar(number_of_slacks, constr_viol_tol_),
                                 bound_relax_factor_ * max(VecRealScalar(number_of_slacks, 1.),
                                                           abs(modified_bounds_lower_)));
        auto updated_upper = modified_bounds_upper_ +
                             min(VecRealScalar(number_of_slacks, constr_viol_tol_),
                                 bound_relax_factor_ * max(VecRealScalar(number_of_slacks, 1.),
                                                           abs(modified_bounds_upper_)));
        lower_bounds = modified_bounds_lower_;
        upper_bounds = modified_bounds_upper_;
        return 0;
    }

} // namespace fatrop

#endif // __fatrop_ip_algorithm_ip_nlp_orig_hxx__
