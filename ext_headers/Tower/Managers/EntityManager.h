#pragma once

#include "pch.h"
#include "framework.h"
#include <Tower/Entity.h>
#include <Tower/Signature.h>
#include <memory>
#include <cassert>
#include <queue>
#include <array>

namespace Tower
{
    class EntityManager
    {
    public:
        ~EntityManager(void);

        static std::shared_ptr<EntityManager> Instance(void);

        Entity CreateEntity(void);

        void DestroyEntity(Entity entity);

        void SetSignature(Entity entity, Signature signature);

        Signature GetSignature(Entity entity);

    private:
        EntityManager(void);

        // TODO: consider writing your own queue
        std::queue<Entity> _entities;
        std::array<Signature, MAX_ENTITIES> _signatures;
        static std::shared_ptr<EntityManager> _instance;
        U32 _activeEntities;
    };
    typedef std::shared_ptr<EntityManager> p_EntityManager;
};