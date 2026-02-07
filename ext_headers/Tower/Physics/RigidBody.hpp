/*
TODO: Add full description later


note about acceleration:

All acceleration is going to be due to forces added to the ForceRegistry
via the PhysicsSystem.

The book seems to indicate the existence of a constant acceleration that
is located in the class. This could be used for gravity, or any other
constant force in a never changing direction.

For now, I am going to remove this constant acceleration, and rely entirely
on the force generation system for forces that are going to act on physics
bodies.

*/
#pragma once

#include "pch.h"
#include "Tower/framework.h"
#include "Tower/Rendering/Renderer.hpp"
#include "Tower/Math/Vector.hpp"
#include "Tower/Math/Quaternion.hpp"
#include "Tower/Math/Matrix.hpp"

namespace Tower
{
    class RigidBody;
    typedef shared_ptr<RigidBody> p_RigidBody;

    class RigidBody
    {
    public:
        RigidBody(void);

        RigidBody(const RigidBody& copy);

        const RigidBody& operator=(const RigidBody& copy);

        ~RigidBody(void);

        void Integrate(F32 delta);

        void CalculateDerivedData(void);

        const Vector& GetPosition(void);

        void AddForce(const Vector& force);

        void AddTorque(const Vector& torque);

        void ClearForces(void);

        void AddForceAtPoint(const Vector& force, const Vector& point);

        void AddForceAtBodyPoint(const Vector& force, const Vector& point);

        real GetInverseMass(void) const;

        void SetInverseMass(real val);

        bool HasFiniteMass(void) const;

        const real GetMass(void);

        void SetMass(real mass);

        void SetInverseInertiaTensor(const Matrix& mat);

        inline void SetId(U32 id) { _id = id; }

        inline U32 GetId(void) const { return _id; }

        inline void SetTransform(p_Transform transform) { _transform = transform; }

        inline p_Transform GetTransform(void) const { return _transform; }

        inline const Matrix& GetInverseInertiaTensor(void) const { return _inverseInertiaTensor; }

        inline const Vector& GetVelocity(void) const { return _velocity; }

        inline void SetVelocity(const Vector& velocity) { _velocity = velocity; }

        inline const Vector& GetRotation(void) const { return _angularVelocity; }

        // TODO: Needs to be changed into an AddRotationalForce function
        inline void SetRotation(const Vector& vec) { _angularVelocity = vec; }

        inline real GetLinearDamping(void) const { return _linearDamping; }

        inline void SetLinearDamping(real val) { _linearDamping = val; }

        inline real GetAngularDamping(void) const { return _angularDamping; }

        inline void SetAngularDamping(real val) { _angularDamping = val; }

    private:
        void _TransformInertiaTensor(void);

        U32 _id;
        real _inverseMass;
        real _linearDamping;
        real _angularDamping;
        Matrix _inverseInertiaTensor;
        Matrix _inverseInertiaTensorInWorld;
        Vector _velocity;
        Vector _angularVelocity;
        Vector _forces;
        Vector _torque;
        // This is a pointer to a Player or NPC's location and rotation info.
        // The physics system is allowed to change this because they are really
        // part of the some entity, at the end of the day.
        p_Transform _transform;
    };//end Class

}//end Namespace
