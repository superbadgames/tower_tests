#pragma once

#include "pch.h"
#include "Tower/framework.h"
#include "Tower/Physics/Particle.hpp"
#include <map>

namespace Tower
{
    class ParticleManager;
    typedef shared_ptr<ParticleManager> p_ParticleManager;

    class ParticleManager
    {
    public:
        ParticleManager(void);

        ParticleManager(const ParticleManager& copy);

        ~ParticleManager(void);

        ParticleManager& operator=(const ParticleManager& copy);

        void Init(U32 entitiesToCreate);

        void Integrate(F32 delta);

        p_Particle GetNext(void);

        p_Particle GetById(U32 id);

        void ReleaseParticle(U32 id);

    private:
        std::map<S32, p_Particle> _activeParticles;
        std::vector<p_Particle> _inactiveParticleStack;


    };
}