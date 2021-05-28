#pragma once

#include "pch.h"
#include "framework.h"
#include <glm/vec3.hpp>

namespace Tower
{
    struct Transform
    {
        glm::vec3 position;
        glm::vec3 rotation;
        glm::vec3 scale;
    };
};