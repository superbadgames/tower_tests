#pragma once

#include "pch.h"
#include "Tower/framework.h"

namespace Tower
{
    class PolarCoords2D;
    typedef shared_ptr<PolarCoords2D> p_PolarCoords2D;

    class PolarCoords2D
    {
    public:
        PolarCoords2D(void);

        PolarCoords2D(const PolarCoords2D& copy);

        ~PolarCoords2D(void);

        PolarCoords2D& operator=(const PolarCoords2D& copy);

        void SetRadius(F32 radius);

        void SetAngle(F32 angle);

        Vector2 GetCartesianCoords(void) const;

        void SetFromCartesianCoords(const Vector2& coords);

    private:
        F32 _radius;
        F32 _angle;

        void _CheckBounds(void);
    };
}