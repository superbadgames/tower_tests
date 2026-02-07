/*

The Physics System is really just a collection of functions that needed a safe namespace to hide in.
It contains the Force Registry, and is what coordinates the Integration functions. This is where
AddForce is called on each Physics Body that has had a force assigned to it via a trigger.

Triggers can be from player input, or from the collision detection.

For instance, it has the Update function that every Particle needs to have called on it.

The Physics System is a singleton. There shouldn't be competing version of physics.

TODO:

- Add a Release function that will release a physics body back to the pool.
  For instance, a ReleaseParticle(S32).

  This has a complication. The way that get next is tracked will have to change to account
  for the release. This can be solved with a S32 _FindNext(void) function.

  Could be done with a map instead of a vector. Next available could then be the ID of the next one.

  Also could be done with a find next inactive.
  Or if there are two lists. One is a list of pointers, where they are treated as stacks.

*/
#pragma once

#include "pch.h"
#include "Tower/framework.h"
#include "Tower/Managers/ConfigurationManager.hpp"
#include "Tower/Managers/ParticleManager.hpp"
#include "Tower/Managers/RigidBodyManager.hpp"
#include "Tower/Physics/Force/ForceRegistry.hpp"
#include <vector>

namespace Tower
{
    class PhysicsSystem;
    typedef shared_ptr<PhysicsSystem> p_PhysicsSystem;

    class PhysicsSystem
    {
    public:
        ~PhysicsSystem(void);

        static p_PhysicsSystem Instance(void);

        void CreateParticles(void);

        void CreateRigidBodies(void);

        p_Particle GetNextParticle(void);

        p_Particle GetParticle(U32 id);

        p_RigidBody GetNextRigidBody(void);

        p_RigidBody GetRigidBody(U32 id);

        void IntegrateParticles(F32 delta);

        void IntegrateRigidBodies(F32 delta);

        void ApplyForces();

        inline void ReleaseParticle(U32 id) { _particleManager.ReleaseParticle(id); }

        inline void ReleaseRigidBody(U32 id) { _rigidBodyManager.ReleaseRigidBody(id); }

        inline void AddForceToParticle(U32 particleId, string name, p_ForceGenerator force) { _forceRegistry.AddForceToParticle(particleId, name, force); }

        inline void AddForceToRigidBody(U32 rigidBodyId, string name, p_ForceGenerator force) { _forceRegistry.AddForceToRigidBody(rigidBodyId, name, force); }


    private:
        static p_PhysicsSystem _instance;
        // Treat as const, should only change in rare exceptions
        U32 MAX_ENTITIES;
        bool _particlesCreated;
        bool _rigidBodiesCreated;
        ParticleManager _particleManager;
        RigidBodyManager _rigidBodyManager;
        ForceRegistry _forceRegistry;


        PhysicsSystem(void);

        // TODO: Consider adding private copy function

        void _Init(void);
    };
}