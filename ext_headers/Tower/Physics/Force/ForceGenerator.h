#pragma once

#include "pch.h"
#include "Tower/framework.h"
#include "Tower/Physics/Particle.hpp"
#include "Tower/Physics/RigidBody.hpp"

namespace Tower
{
    class ForceGenerator;
    typedef shared_ptr<ForceGenerator> p_ForceGenerator;

    class ForceGenerator
    {
    public:
        ForceGenerator(void);

        virtual ~ForceGenerator(void);

        virtual void v_UpdateForce(p_Particle body) {}

        virtual void v_UpdateForce(p_RigidBody boyd) {}

    };
}
