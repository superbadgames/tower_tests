#pragma once

#include "pch.h"
#include "Tower/framework.h"
#include "Tower/Math/Transform.hpp"
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

        void v_SetViewDirection(const EulerAngle& euler) final;

        inline void SetOffset(const glm::vec2& offset) { _cameraOffset = offset; }

        inline const Matrix& GetViewMatrix(void) const { return _viewMatrix; }

        inline void SetTarget(p_Transform target) { _targetTransform = target; }

    private:
        F32 _followDistance;
        F32 _viewSensitivity;
        Vector _up;
        Vector _eye;
        Vector _cameraForward;
        Vector _cameraLeft;
        Vector _cameraUp;
        glm::vec2 _cameraOffset;
        p_Transform _targetTransform;
        Vector _viewDirection;
    };
}