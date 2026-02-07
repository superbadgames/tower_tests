#pragma once

#include "pch.h"
#include "Tower/framework.h"
#include "Tower/Systems/PhysicsSystem.hpp"
#include "Tower/Physics/Force/ForceGenerator.h"
#include "Tower/Physics/Particle.hpp"
#include "Tower/Physics/RigidBody.hpp"
#include <vector>


namespace Tower
{
    class ForceRegistry;
    typedef shared_ptr<ForceRegistry> p_ForceRegistry;

    class ForceRegistry
    {
    public:
        ForceRegistry(void);

        ForceRegistry(const ForceRegistry& copy);

        ~ForceRegistry(void);

        ForceRegistry& operator=(const ForceRegistry& copy);

        void AddForceToParticle(U32 particleId, string name, p_ForceGenerator forceGen);

        void AddForceToRigidBody(U32 rigidBodyId, string name, p_ForceGenerator forceGen);

        void RemoveForceFromParticle(U32 particleId, string name);

        void RemoveForceFromRigidBody(U32 rigidBodyId, string name);

        void Clear(void);

        // TODO: Consider replacing this with two calls
        // ApplyParticleForces and ApplyRigidBodyForces
        void ApplyForces(void);

    private:
        struct ForceRegistration
        {
            string name;
            p_ForceGenerator force;
        };

        std::map<S32, std::vector<ForceRegistration>> _particleRegistrations;
        std::map<S32, std::vector<ForceRegistration>> _rigidBodyRegistrations;

    };
}
