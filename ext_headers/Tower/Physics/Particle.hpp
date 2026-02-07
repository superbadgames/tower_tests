/*

A Particle is the simplest object that can be simulated in the physics engine.

*/

#pragma once

#include "pch.h"
#include "Tower/framework.h"
#include "Tower/Math/Transform.hpp"
#include <glm/vec3.hpp>

namespace Tower
{
    class Particle;
    typedef shared_ptr<Particle> p_Particle;

    class Particle
    {
    public:
        Particle(void);

        Particle(const Particle& copy);

        Particle& operator=(const Particle& copy);

        Particle(p_Transform transform);

        ~Particle(void);

        inline void SetId(U32 id) { _id = id; }

        inline U32 GetId(void) const { return _id; }

        inline void SetTransform(p_Transform transform) { _transform = transform; }

        inline p_Transform GetTransform(void) { return _transform; }

        inline void SetInverseMass(F32 inverse) { _inverseMass = inverse; }

        inline void SetDamping(F32 damping) { _damping = damping; }

        inline const Vector& GetVelocity(void) const { return _velocity; }

        // Use with caution! This should really only be changed by the physics system
        inline void SetVelocity(const Vector& velocity) { _velocity = velocity; }

        inline void SetVelocity(F32 x, F32 y, F32 z) { _velocity.Set(x, y, z); }

        void SetMass(F32 mass);

        void Integrate(F32 delta);

        void AddForce(const Vector& force);

    private:
        U32 _id;
        Vector _velocity;
        // 0.0 = 100% drag, no velocity after integration
        // 1.0f = no drag. Maybe 0.999 is better for the math
        F32 _damping;
        // Inverse to simplify math in the integrator.
        // An inverse mass of 0.0 implies an infinite mass,
        // thus acceleration will have no effect on the initial velocity
        F32 _inverseMass;
        // A representation of all the accumulated forces that are acting
        // on the object for this frame. Cleared each frame
        // Each force is basically the acceleration that will change the
        // value of the velocity
        Vector _forces;
        // This is a pointer to a Player or NPC's location and rotation info.
        // The physics system is allowed to change this because they are really
        // part of the some entity, at the end of the day.
        p_Transform _transform;

        void _ClearForces(void);
    };
}