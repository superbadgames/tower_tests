/*

A generalized interface for all the cameras in the engine.

I decided to use less instead of more. I'm only defining the bear minimum function that I need.

*/
#pragma once

#include "Tower/framework.h"
#include "Tower/Managers/ConfigurationManager.hpp"
#include "Tower/Math/Matrix.hpp"

namespace Tower
{
    class Camera;
    typedef shared_ptr<Camera> p_Camera;

    class Camera
    {
    public:
        Camera(void);

        Camera(const Camera& copy);

        Camera& operator=(const Camera& copy);

        virtual ~Camera(void) {};

        // Should call either InitOrthographic or InitPerspective
        virtual void v_Init(void) = 0;

        virtual void v_Update(F32 delta) {}

        virtual void v_MoveForward(F32 speed) {};

        virtual void v_MoveBack(F32 speed) {};

        virtual void v_MoveRight(F32 speed) {};

        virtual void v_MoveLeft(F32 speed) {};

        virtual void v_MoveUp(F32 speed) {};

        virtual void v_MoveDown(F32 speed) {};

        inline const Matrix& GetViewMatrix(void) const { return _viewMatrix; }

        inline const Matrix& GetPerspectiveMatrix(void) const { return _perspectiveMatrix; }

        inline const Matrix& GetOrthographicMatrix(void) const { return _orthographicMatrix; }

        inline const Vector& GetPosition(void) const { return _position; }

        // Virtual so that other actions can take place here, if needed, such as recalculating a viewMatrix
        inline virtual void v_SetPosition(const Vector& position) { _position = position; }

        inline virtual void v_SetViewDirection(const EulerAngle& euler) { }

    protected:
        Matrix _viewMatrix;
        Matrix _perspectiveMatrix;
        Matrix _orthographicMatrix;
        // Why isn't this a transform?
        Vector _position;

        void _DefaultInit(void);

        void _InitOrthographic(F32 screenWidth, F32 screenHeight, F32 viewDistance);

        void _InitPerspective(F32 fieldOfView, F32 aspectRation, F32 viewDistance);
    };
}