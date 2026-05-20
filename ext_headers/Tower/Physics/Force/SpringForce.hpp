#pragma once

//=====Engine Includes=====
#include "pch.h"
#include "Tower/framework.h"
#include "Tower/Physics/Force/ForceGenerator.h"
#include <glm/vec4.hpp>

namespace Tower
{
    class SpringForce: public ForceGenerator
    {
    public:
        SpringForce(void);

        ~SpringForce(void);

        void MakeBungie(bool state)
        {
            _isBungie = state;
        }



        inline void SetSpringConstant(F32 constant)
        {
            _springConstant = constant;
        }

        inline void SetRestLength(F32 length)
        {
            _restLength = length;
        }

    private:
        F32 _springConstant;
        F32 _restLength;
        bool _isBungie;

    };//end SpringForce
    typedef shared_ptr<SpringForce> p_SpringForce;
}//end Namespace