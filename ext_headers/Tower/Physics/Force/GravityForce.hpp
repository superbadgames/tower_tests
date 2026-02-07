#pragma once

//=====Engine includes=====
#include "pch.h"
#include "Tower/framework.h"
#include "Tower/Physics/Force/ForceGenerator.h"
#include <glm/vec2.hpp>
#include <glm/vec3.hpp>


namespace Tower
{
    class GravityForce : public ForceGenerator
    {
    public:
        GravityForce(void);

        GravityForce(const Vector& gravity);

        ~GravityForce(void);

        void v_UpdateForce(p_Particle body) final;

        inline void SetGravity(const Vector& gravity) { _gravity = gravity; }

        inline void SetFloor(F32 floor) { _floor = floor; }

        inline const Vector& GetGravityValue(void) const { return _gravity; }

        inline const F32 GetFloor(void) const { return _floor; }


    private:
        F32 _floor;
        Vector _gravity;
    };//end class
    typedef shared_ptr<GravityForce> p_GravityForce;
}//end namespace