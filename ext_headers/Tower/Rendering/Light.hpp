#pragma once

#include "pch.h"
#include "Tower/framework.h"
#include <glm/vec3.hpp>

namespace Tower
{
    class Light
    {
    public:
        Light(void);

        Light(glm::vec3 color, glm::vec3 direction, F32 ambient, F32 diffuse);

        ~Light(void);

        //  void UpdateGPU(Shader &shader);

          // void inline SetColor(glm::vec3 color)
          // {
          //     _color = color;
          // }

          // void inline SetDirection(glm::vec3 direction)
          // {
          //     _direction = direction;
          // }

          // void inline SetAmbient(real ambient)
          // {
          //     _ambient = ambient;
          // }

          // void inline SetDiffuse(real diffuse)
          // {
          //     _diffuse = diffuse;
          // }

    private:
        glm::vec3 _color;
        glm::vec3 _direction;
        F32 _diffuse;
        F32 _ambient;
    };
}