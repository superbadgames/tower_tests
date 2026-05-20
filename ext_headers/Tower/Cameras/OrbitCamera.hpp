/*

The Arcball

The orbit effect is created by creating a sphere around the target. The camera has a position
on this sphere. When input is received, the camera changes it's position on this sphere.

The Vector _arcball stores the location of the camera on the sphere.
_CalculatePositionFromArcball changes this into Cartesian coordinates, in local space, with the
target position acting as an origin.

In _arcball:

X = distance of the position from the origin, essentially the same as the radius
Y = angle theta, or the horizontal angle. This is the yaw of the camera, or the rotation around the target
Z = angle phi, or the vertical angle. This is the pitch of the camera, or the rotation looking up or down towards the target.

*/
#pragma once

#include "pch.h"
#include "Tower/framework.h"
#include "Tower/Math/Transform.hpp"
#include "Tower/Math/PolarCoords3D.hpp"
#include "Tower/Cameras/Camera.hpp"
#include "Tower/Managers/InputManager.hpp"

namespace Tower
{
    class OrbitCamera;
    typedef shared_ptr<OrbitCamera> p_OrbitCamera;

    class OrbitCamera : public Camera
    {
    public:
        OrbitCamera(void);

        OrbitCamera(const OrbitCamera& copy);

        OrbitCamera& operator=(const OrbitCamera& copy);

        ~OrbitCamera(void) final;

        void v_Init(void) final;

        void v_Update(F32 delta) final;

        void v_SetPosition(const Vector& pos) final;

        void SetRadius(F32 radius);

        inline void SetUp(const Vector& up) { _up = up; }

        inline void SetTarget(p_Transform target) { _target = target; }

        inline void SetMovementSensitivity(F32 val) { _movementSensitivity = val; }

    private:
        F32 _radius;
        F32 _movementDeadzone;
        F32 _movementSensitivity;
        Vector _up;
        Vector _eye;
        Vector _cameraForward;
        Vector _cameraLeft;
        Vector _cameraUp;
        PolarCoords3D _arcball;
        p_Transform _target;

        void _CalculateCameraBasis(void);

        void _CalculatePositionFromArcball(void);

    };
}