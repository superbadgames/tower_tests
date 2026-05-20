#pragma once

#include "pch.h"
#include "Tower/framework.h"
#include "Tower/Math/Vector.hpp"

namespace Tower
{
    class PolarCoords3D;
    typedef shared_ptr<PolarCoords3D> p_PolarCoords3D;

    class PolarCoords3D
    {
    public:
        PolarCoords3D(void);

        PolarCoords3D(const PolarCoords3D& copy);

        ~PolarCoords3D(void);

        PolarCoords3D& operator=(const PolarCoords3D& copy);

        Vector GetCartesianCoords(void) const;

        void SetFromCartesianCoords(const Vector& coords);

        void SetRadius(F32 radius);

        void SetHeadingRadian(F32 h);

        void SetHeadingDegree(F32 h);

        void SetPitchRadian(F32 p);

        void SetPitchDegree(F32 p);

        inline F32 GetRadius(void) const { return _radius; }

        inline F32 GetHeading(void) const { return _heading; }

        inline F32 GetPitch(void) const { return _pitch; }

    private:
        F32 _radius;
        F32 _heading;
        F32 _pitch;

        void _CheckBounds(void);
    };
}