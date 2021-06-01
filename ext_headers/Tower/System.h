#pragma once

#include "pch.h"
#include "framework.h"
#include "Tower/Entity.h"
#include <set>

namespace Tower
{
    class System
    {
    public:
        std::set<Entity> Entities;
    };
    typedef shared_ptr<System> p_System;
}