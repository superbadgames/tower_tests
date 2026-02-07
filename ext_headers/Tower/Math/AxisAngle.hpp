#pragma once

#include "pch.h"
#include "Tower/framework.h"
#include <glm/vec3.hpp>
#include <glm/gtx/quaternion.hpp>

namespace Tower
{
    class AxisAngle;
    typedef shared_ptr<AxisAngle> p_AxisAngle;

    class AxisAngle
    {
    public:
        AxisAngle(void);

        AxisAngle(const glm::vec3& axis, F32 angle);

        AxisAngle(const AxisAngle& copy);

        ~AxisAngle(void);

        AxisAngle& operator=(const AxisAngle& copy);

        glm::quat ToQuat(void) const;

        void SetAngle(F32 angle) { _angle = angle; }

        void SetAxis(const glm::vec3& axis);

        inline const glm::vec3& GetAxis(void) const { return _axis; }

    private:
        // Angle of rotation in degrees
        F32 _angle;
        glm::vec3 _axis;
    };
}