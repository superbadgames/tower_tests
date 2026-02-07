#pragma once

#include "pch.h"
#include "Tower/framework.h"
#include "Tower/Input/InputButtons.hpp"
#include "Tower/Input/InputButtonState.hpp"
#include "Tower/Math/Vector2.hpp"
#include <map>

namespace Tower
{
    class InputManager
    {
    public:
        ~InputManager(void);

        static shared_ptr<InputManager> Instance(void);

        void InputEventDetected(ButtonPress update);

        void UpdateBindings(void);

        bool IsBindingPressed(const string& name);

        bool IsBindingHeld(const string& name);

        bool IsBindingReleased(const string& name);

        bool IsBindingPressedOrHeld(const string& name);

        void AddBinding(const string& name, Tower::InputButton button);

        void SetMouseCursorPosition(const Vector2& position);

        const Vector2& GetMouseCurrentCursorPosition(void) const;

        const Vector2& GetMousePreviousCursorPosition(void) const;

        Vector2 GetMouseInputOffset(void);

        void AddWASDMovement(const string& forward = "move_forward",
            const string& back = "move_back",
            const string& right = "move_right",
            const string& left = "move_left");

        void AddArrowMovement(const string& forward = "move_forward",
            const string& back = "move_back",
            const string& right = "move_right",
            const string& left = "move_left");

    private:
        static shared_ptr<InputManager> _instance;
        // TODO: Learn how to hash this string
        std::map<string, InputButton> _registeredBindings;
        std::map<string, InputButtonState> _bindingChangeState;
        std::map<string, InputButtonState> _activeBindingStates;
        Vector2 _mousePreviousPosition;
        Vector2 _mouseCurentPosition;
        Vector2 _mouseInputOffset;
        F32 _mouseSensitivity;
        bool _mouseUpdatedThisFrame;
        bool _firstMouse;

        InputManager(void);

    };
    typedef  shared_ptr<InputManager> p_InputManager;
}