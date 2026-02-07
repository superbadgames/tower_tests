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



        inline void SetSpringConstant(real constant)
        {
            _springConstant = constant;
        }

        inline void SetRestLength(real length)
        {
            _restLength = length;
        }

    private:

        real _springConstant;
        real _restLength;
        bool _isBungie;

    };//end SpringForce
    typedef shared_ptr<SpringForce> p_SpringForce;
}//end Namespace