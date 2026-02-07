#pragma once

#include "pch.h"
#include "Tower/framework.h"
#include <glm/vec2.hpp>
#include <glm/geometric.hpp>

namespace Tower
{
    class Vector2;
    typedef shared_ptr<Vector2> p_Vector2;

    class Vector2
    {
    public:
        Vector2(void);

        Vector2(const Vector2& copy);

        explicit Vector2(const glm::vec2& value);

        Vector2(F32 xVal, F32 yVal);

        ~Vector2(void);

        Vector2& operator=(const Vector2& copy);

        Vector2 operator+(const Vector2& other) const;

        Vector2 operator+(F32 value) const;

        Vector2& operator+=(const Vector2& other);

        Vector2& operator+=(F32 value);

        Vector2 operator-(const Vector2& other) const;

        Vector2 operator-(F32 value) const;

        Vector2& operator-=(const Vector2& other);

        Vector2& operator-=(F32 value);

        Vector2 operator*(F32 value);

        Vector2& operator*=(F32 value);

        // The so called Dot, or Scalar operator
        F32 operator*(const Vector2& other) const;

        F32 Dot(const Vector2& other) const;

        void Normalize(void);

        inline F64 Length(void) const { return glm::length(_vec); }

        inline void SetAll(F32 val) { _vec.x = _vec.y = val; }

        inline void Set(F32 x, F32 y, F32 z) { _vec.x = x; _vec.y = y; }

        inline void SetX(F32 x) { _vec.x = x; }

        inline F32 GetX(void) const { return _vec.x; }

        inline void SetY(F32 y) { _vec.y = y; }

        inline F32 GetY(void) const { return _vec.y; }

        inline const glm::vec2& GetRaw(void) const { return _vec; }

    private:
        glm::vec2 _vec;
    };
}