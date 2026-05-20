#pragma once

#include "pch.h"
#include "Tower/framework.h"
#include <glm/vec3.hpp>
#include <glm/gtx/norm.hpp>

namespace Tower
{
    class BoundingSphere
    {

    public:
        BoundingSphere(void);

        BoundingSphere(const glm::vec3& center, F32 radius);

        BoundingSphere(const BoundingSphere& one, const BoundingSphere& two);

        ~BoundingSphere(void);

        bool TestCollision(const BoundingSphere& other) const;

        F32 GetGrowth(BoundingSphere& other) const;

        F32 GetSize(void) const;

        void SetCenter(const glm::vec3& pos);

        void SetCenter(F32 x, F32 y, F32 z);

        const glm::vec3& GetCenter(void) const;

        void SetRadius(F32 r);

        F32 GetRadius(void) const;

    private:
        glm::vec3 _center;
        F32 _radius;

    };//end Class
    typedef shared_ptr<BoundingSphere> p_BoundingSphere;
}//end Namespace
