#pragma once

#include "pch.h"
#include "Tower/framework.h"
#include <glm/vec3.hpp>
#include <glm/geometric.hpp>

namespace Tower
{
    class Point;
    typedef shared_ptr<Point> p_Point;

    class Point
    {
    public:
        Point(void);

        Point(const Point& copy);

        explicit Point(const glm::vec3& value);

        Point(F32 xVal, F32 yVal);

        Point(F32 xVal, F32 yVal, F32 zVal);

        ~Point(void);

        Point& operator=(const Point& copy);

        Point operator+(const Point& other) const;

        Point operator+(F32 value) const;

        Point& operator+=(const Point& other);

        Point& operator+=(F32 value);

        Point operator-(const Point& other) const;

        Point operator-(F32 value) const;

        Point& operator-=(const Point& other);

        Point& operator-=(F32 value);

        Point operator*(F32 value);

        Point& operator*=(F32 value);

        // The so called Dot, or Scalar operator
        F32 operator*(const Point& other) const;

        F32 Dot(const Point& other) const;

        Point Cross(const Point& other) const;

        void Normalize(void);

        inline F64 Length(void) const { return glm::length(_vec); }

        inline void SetAll(F32 val) { _vec.x = _vec.y = _vec.z = val; }

        inline void Set(F32 x, F32 y, F32 z) { _vec.x = x; _vec.y = y; _vec.z = z;  }

        inline void Set(const glm::vec3& vec) { _vec = vec; }

        inline void SetX(F32 x) { _vec.x = x; }

        inline F32 GetX(void) const { return _vec.x; }

        inline void SetY(F32 y) { _vec.y = y; }

        inline F32 GetY(void) const { return _vec.y; }

        inline void SetZ(F32 z) { _vec.z = z; }

        inline F32 GetZ(void) const { return _vec.z; }

        inline const glm::vec3& GetRaw(void) const { return _vec; }

    private:
        glm::vec3 _vec;
    };
}