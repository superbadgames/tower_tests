#pragma once

/*
Class Description:

A class Vector, it is a 4 degree vector. The W component is going to be treated as a special case.
When operations are performed, like the Cross Product, for instance, where the W component doesn't
fit, it will be ignored and treated as a 3D vector.

This is true for Addition and Subtraction too

*/

#include "pch.h"
#include "Tower/framework.h"
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>
#include <glm/geometric.hpp>

namespace Tower
{
    class Vector;
    typedef shared_ptr<Vector> p_Vector;

    class Vector
    {
    public:
        Vector(void);

        Vector(const Vector& copy);

        Vector(F32 xVal, F32 yVal);

        Vector(F32 xVal, F32 yVal, F32 zVal);

        ~Vector(void);

        Vector& operator=(const Vector& copy);

        Vector operator+(const Vector& other) const;

        Vector operator+(F32 value) const;

        Vector& operator+=(const Vector& other);

        Vector& operator+=(F32 value);

        Vector operator-(const Vector& other) const;

        Vector operator-(F32 value) const;

        Vector& operator-=(const Vector& other);

        Vector& operator-=(F32 value);

        Vector operator*(F32 value);

        Vector& operator*=(F32 value);

        // The so called Dot, or Scalar operator
        F32 operator*(const Vector& other) const;

        F32 Dot(const Vector& other) const;

        Vector Cross(const Vector& other) const;

        F32 Length(void) const;

        F32 SquaredLength(void) const;

        void Normalize(void);

        inline void SetAll(F32 val) { _vec[X] = _vec[Y] = _vec[Z] = val; }

        inline void Set(F32 x, F32 y, F32 z) { _vec[X] = x; _vec[Y] = y; _vec[Z] = z; }

        inline void SetX(F32 x) { _vec[X] = x; }

        inline F32 GetX(void) const { return _vec[X]; }

        inline void SetY(F32 y) { _vec[Y] = y; }

        inline F32 GetY(void) const { return _vec[Y]; }

        inline void SetZ(F32 z) { _vec[Z] = z; }

        inline F32 GetZ(void) const { return _vec[Z]; }

        inline const F32* GetRaw(void) const { return _vec; }

    private:
        const U32 X = 0;
        const U32 Y = 1;
        const U32 Z = 2;
        const U32 W = 3;

        F32 _vec[4];
    };
}