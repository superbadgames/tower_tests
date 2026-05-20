#pragma once

//=====Engine includes=====
#include "pch.h"
#include "Tower/framework.h"
#include "Tower/Physics/Force/ForceGenerator.h"
#include "Tower/Physics/RigidBody.hpp"
#include <glm/vec2.hpp>
#include <glm/vec3.hpp>


namespace Tower
{
    class DragForce : public ForceGenerator
    {
    public:
        DragForce(void);

        DragForce(F32 drag);

        ~DragForce(void);

        void v_UpdateForce(p_Particle body) final;

        inline void SetDrag(F32 d)
        {
            _drag = d;
            _dragSqr = _drag * _drag;
        }

        inline F32 GetDrag(void)
        {
            return _drag;
        }

    private:
        F32 _drag;
        F32 _dragSqr;
    };//end class
    typedef shared_ptr<DragForce> p_DragForce;
}//end namespace