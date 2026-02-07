#pragma once

#include "pch.h"
#include "Tower/framework.h"
#include "Tower/Math/Quaternion.hpp"
#include <glm/vec3.hpp>
#include <glm/gtc/quaternion.hpp>

namespace Tower
{
    class EulerAngle;
    typedef shared_ptr<EulerAngle> p_EulerAngle;

    // Forward declaration
    class Quaternion;

    class EulerAngle
    {
    public:
        EulerAngle(void);

        EulerAngle(const EulerAngle& copy);

        EulerAngle(F32 x, F32 y, F32 z);

        ~EulerAngle(void);

        EulerAngle& operator=(const EulerAngle& copy);

        inline glm::vec3 ToVec3(void) const { return glm::vec3(_pitch, _yaw, _roll); }

        inline void SetYaw(F32 yaw) { _yaw = yaw; }

        inline F32 GetYaw(void) const { return _yaw; }

        inline void SetPitch(F32 pitch) {_pitch = pitch; }

        inline F32 GetPitch(void) const { return _pitch; }

        inline void SetRoll(F32 roll) { _roll = roll; }

        inline F32 GetRoll(void) const { return _roll; }

        inline void Set(F32 val) { _yaw = _pitch = _roll = val; }

    private:
        // In Degrees
        // aka
        // x
        F32 _yaw;
        // y
        F32 _pitch;
        // z
        F32 _roll;

        void _Clamp(void);

    };
}