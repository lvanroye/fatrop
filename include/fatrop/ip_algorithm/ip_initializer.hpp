//
// Copyright (C) 2024 Lander Vanroye, KU Leuven
//

#ifndef __fatrop_ip_algorithm_ip_initializer_hpp__
#define __fatrop_ip_algorithm_ip_initializer_hpp__
#include "fatrop/ip_algorithm/fwd.hpp"
#include <memory>
namespace fatrop
{
    class IpInitializerBase
    {
    public:
        virtual void initialize() = 0;

    protected:
        virtual ~IpInitializerBase() = default;
    };

    template <typename ProblemType> class IpInitializer : public IpInitializerBase
    {
        typedef std::shared_ptr<IpEqMultInitializer<ProblemType>> IpEqMultInitializerSp;
        typedef std::shared_ptr<IpData<ProblemType>> IpDataSp;

    public:
        IpInitializer(const IpDataSp ipdata, const IpEqMultInitializerSp &eq_mult_initializer);
        void initialize() override;
    private:
        void initialize_slacks();
        IpDataSp ipdata_;
        IpEqMultInitializerSp eq_mult_initializer_;
        Scalar bound_push = 1e-2; // kappa_1
        Scalar bound_frac = 1e-2; // kappa_2
    };

} // namespace fatrop

#endif // __fatrop_ip_algorithm_ip_initializer_hpp__