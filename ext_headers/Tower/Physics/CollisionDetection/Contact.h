#pragma once

//=====Engine Includes=====
#include "pch.h"
#include "Tower/framework.h"
#include <glm/vec4.hpp>

namespace Tower
{
    class Contact
    {
    public:
        Contact(void);

        ~Contact(void);

    private:
        glm::vec4 _contactPoint;
        glm::vec4 _collisionNormal;
        F32 _penetrationDepth;
        F32 _collisionRestitution;
        F32 _friction;
    };//end Class
    typedef shared_ptr<Contact> p_Contact;
}//end Namespace
