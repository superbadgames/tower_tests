#pragma once

#include "pch.h"
#include "framework.h"
#include "Tower/Component.h"
#include "Tower/Components/ComponentArray.h"

#include <unordered_map>
#include <memory>

namespace Tower
{
    class ComponentManager
    {
    public:
        ComponentManager(void) {}
        ~ComponentManager(void) {}

        template<typename T>
        void RegisterComponent(void)
        {
            const char* typeName = typeid(T).name();

            // If the component type has been registered, early out, move on.
            if(_componentTypes.find(typeName) != _componentTypes.end())
            {
                return;
            }

            _componentTypes.insert({typeName, _nextComponentType});

            _componentArrays.insert({ typeName, std::make_shared<ComponentArrary<T>>() });
            ++_nextComponentType;
        }

        template<typename T>
        ComponentType GetComponentType(void)
        {
            const char* typeName = typeid(T).name;

            assert(_componentTypes.find(typeName) == _componentTypes.end() && "ComponentManager failed GetComponentType. No such Component registered before call.");

            return _componentTypes[typeName];
        }

        template<typename T>
        void AddComponent(Entity entity, T component)
        {
            _GetComponentArray<T>()->InsertData(entity, component);
        }

        template<typename T>
        void RemoveComponent(Entity entity)
        {
            _GetComponentArray<T>()->RemoveData(entity);
        }

        template<typename T>
        T& GetComponent(Entity entity)
        {
            return _GetComponentArray<T>()->GetData(entity);
        }

        void EntityDestroyed(Entity entity);

    private:
        std::unordered_map<const char*, ComponentType> _componentTypes;
        std::unordered_map<const char*, p_IComponentArray> _componentArrays;
        ComponentType _nextComponentType;

        template<typename T>
        shared_ptr<ComponentArrary<T>> _GetComponentArray(void)
        {
            const char* typeName = typeid(T).name();

            assert(_componentTypes.find(typeName) != _componentTypes.end() && "ComponentManager failed _GetComponentArray. No Components registered.");

            return std::static_pointer_cast<ComponentArrary<T>>(_componentArrays[typeName]);
        }
    };
}