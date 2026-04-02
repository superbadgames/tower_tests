#pragma once

#include "pch.h"
#include "Tower/framework.h"
#include "Tower/Math/EulerAngle.hpp"
#include "Tower/Math/Matrix.hpp"
#include <glm/gtc/quaternion.hpp>

namespace Tower
{
    class Quaternion;
    typedef shared_ptr<Quaternion> p_Quaternion;

    // Forward declaration
    class Matrix;
    class EulerAngle;

    class Quaternion
    {
    public:
        Quaternion(void);

        Quaternion(const Quaternion& copy);

        Quaternion(F32 x, F32 y, F32 z, F32 w);

        ~Quaternion(void);

        const Quaternion& operator=(const Quaternion& copy);

        EulerAngle GetHumanReadable(void) const;

        Vector ToVector(void) const;

        void Set(F32 x, F32 y, F32 z, F32 w);

        void Set(const EulerAngle& euler);

        void Set(const Vector& vector);

        inline void Normalize(void) { _quaternion = glm::normalize(_quaternion); }

        inline void SetX(F32 x) { _quaternion.x = x; }

        inline F32 GetX(void) const { return _quaternion.x; }

        inline void SetY(F32 y) { _quaternion.y = y; }

        inline F32 GetY(void) const { return _quaternion.y; }

        inline void SetW(F32 w) { _quaternion.w = w; }

        inline F32 GetW(void) const { return _quaternion.w; }

        inline const glm::quat& GetRaw(void) const { return _quaternion; }

    private:
        glm::quat _quaternion;

    };
}