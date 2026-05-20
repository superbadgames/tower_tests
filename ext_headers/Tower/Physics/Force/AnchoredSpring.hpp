#pragma once

#include "pch.h"
#include "Tower/framework.h"
#include "Tower/Physics/Force/ForceGenerator.h"
#include <glm/vec3.hpp>


namespace Tower
{
    class AnchoredSpring: public ForceGenerator
    {
    public:
        AnchoredSpring(void);

        AnchoredSpring(const glm::vec3& anchor, F32 springConstant, F32 restLength);

        ~AnchoredSpring(void);

        void v_UpdateForce(p_Particle body) final;

        void SetAnchor(const glm::vec3& anchor);

        void SetSpringConstant(F32 constant);

        void SetRestLength(F32 length);

    private:
        glm::vec3 _anchor;
        F32 _springConstant;
        F32 _restLength;
    };//end AnchoredSpring
    typedef shared_ptr<AnchoredSpring> p_AnchoredSpring;
}//end Namespace