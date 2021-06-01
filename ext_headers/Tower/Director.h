#pragma once

#include "pch.h"
#include "framework.h"
#include "Tower/Entity.h"
#include "Tower/Component.h"
#include "Tower/Managers/EntityManager.h"
#include "Tower/Managers/ComponentManager.h"
#include "Tower/Managers/SystemManager.h"

namespace Tower
{
    class Director
    {
    public:
        ~Director(void);

        static shared_ptr<Director> Instance(void);

        void Init(void);

        Entity CreateEntity(void);

        void DestroyEntity(Entity entity);

        template<typename T>
        void RegisterComponent(void)
        {
            _componentManager->RegisterComponent<T>();
        }

        template<typename T>
        void AddComponent(Entity entity, T component)
        {
            _componentManager->AddComponent<T>(entity, component);

            auto signature = _entityManager->GetSignature(entity);
            signature.set(_componentManager->GetComponentType<T>(), true);
            _entityManager->SetSignature(entity, signature);

            _systemManager->EntitySignatureChanged(entity, signature);
        }

        template <typename T>
        void RemoveComponent(Entity entity)
        {
            _componentManager->RemoveComponent<T>(entity);

            auto signature = _entityManager->GetSignature(entity);
            signature.set(_componentManager->GetComponentType<T>(), false);
            _entityManager->SetSignature(entity, signature);

            _systemManager->EntitySignatureChanged(entity, signature);
        }

        template <typename T>
        T& GetComponent(Entity entity)
        {
            return _componentManager->GetComponent<T>(entity);
        }

        template <typename T>
        ComponentType GetComponentType(void)
        {
            return _componentManager->GetComponentType<T>();
        }

        template <typename T>
        shared_ptr<T> RegisterSystem()
        {
            return _systemManager->RegisterSystem<T>();
        }

        template <typename T>
        void SetSystemSignature(Signature signature)
        {
            _systemManager->SetSignature<T>(signature);
        }

    private:
        static shared_ptr<Director> _instance;
        unique_ptr<EntityManager> _entityManager;
        unique_ptr<ComponentManager> _componentManager;
        unique_ptr<SystemManager> _systemManager;

        Director(void);
    };
    typedef shared_ptr<Director> p_Director;
}