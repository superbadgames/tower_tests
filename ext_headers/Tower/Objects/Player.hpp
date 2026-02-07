#pragma once

#include "pch.h"
#include "Tower/framework.h"
#include "Tower/Rendering/Renderer.hpp"
#include "Tower/Math/Transform.hpp"
#include "Tower/Cameras/Camera.hpp"
#include "Tower/Managers/InputManager.hpp"

#include <glm/gtx/transform.hpp>

namespace Tower
{
    class Player;
    typedef shared_ptr<Player> p_Player;

    class Player
    {
    public:
        Player(void);

        Player(const Player& copy);

        Player& operator=(const Player& copy);

        virtual ~Player(void);

        virtual void v_Init(const Vector& position) = 0;

        virtual void v_Activate(void) = 0;

        virtual void v_Deactivate(void) = 0;

        virtual void v_Update(F32 delta) = 0;

        inline bool IsActive(void) const { return _active; }

        inline void ToggleActive(bool state) { _active = state; }

        inline bool IsRendering(void) const { return _renderer->IsRendering(); }

        inline void ToggleRendering(bool state) { _renderer->ToggleRendering(state); }

        inline p_Renderer GetRenderer(void) const { return _renderer; }

        inline p_Transform GetTransform(void) const { return _transform; }

        p_Camera GetCamera(void) const { return _camera; }

    protected:
    // Replace later with a call to get the velocity from the rigidbody
    p_Renderer _renderer;
    p_Transform _transform;
    p_Camera _camera;

    void _DefaultInit(void);

    inline void _DefaultActivate(void) { _active = true; }

    inline void _DefaultDeactivate(void) { _active = false; }

    inline bool _isActive(void) const { return _active; }

    private:
        bool _active;
    };
}