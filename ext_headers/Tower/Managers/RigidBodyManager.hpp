#pragma once

#include "pch.h"
#include "Tower/framework.h"
#include "Tower/Physics/RigidBody.hpp"

namespace Tower
{
    class RigidBodyManager;
    typedef shared_ptr<RigidBodyManager> p_RigidBodyManager;

    class RigidBodyManager
    {
    public:
        RigidBodyManager(void);

        RigidBodyManager(const RigidBodyManager& copy);

        ~RigidBodyManager(void);

        RigidBodyManager& operator=(const RigidBodyManager& copy);

        void Init(U32 entitiesToCreate);

        void Integrate(F32 delta);

        p_RigidBody GetNext(void);

        p_RigidBody GetById(S32 id);

        void ReleaseRigidBody(S32 id);

    private:
        std::map<S32, p_RigidBody> _activeRigidBodies;
        std::vector<p_RigidBody> _inactiveRigidBodyStack;

    };
}