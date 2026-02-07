#pragma once

#include "pch.h"
#include "Tower/framework.h"
#include "Tower/Math/Transform.hpp"
#include "Tower/Cameras/Camera.hpp"
#include "Tower/Managers/InputManager.hpp"

namespace Tower
{
    class FollowCamera;
    typedef shared_ptr<FollowCamera> p_FollowCamera;

    class FollowCamera : public Camera
    {
    public:
        FollowCamera(void);

        FollowCamera(const FollowCamera& copy);

        FollowCamera& operator=(const FollowCamera& copy);

        ~FollowCamera(void) final;

        void v_Init(void) final;

        void v_Update(F32 delta) final;

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
    };
}