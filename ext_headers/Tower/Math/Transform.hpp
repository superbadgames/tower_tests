#pragma once

#include "pch.h"
#include "Tower/framework.h"
#include "Tower/Math/Vector.hpp"
#include "Tower/Math/EulerAngle.hpp"
#include "Tower/Math/Quaternion.hpp"
#include "Tower/Math/Matrix.hpp"


namespace Tower
{
    class Transform;
    typedef shared_ptr<Transform> p_Transform;

    class Transform
    {
    public:
        Transform(void);

        Transform(const Transform& copy);

        Transform& operator=(const Transform& copy);

        Vector operator*(const Vector& other);

        Matrix operator*(const Matrix& other);

        ~Transform(void);

        void Reset(void);

        void SetPosition(F32 x, F32 y, F32 z);

        void SetPosition(const Vector& position);

        void UpdatePosition(const Vector& vector);

        void SetScale(const Vector& scale);

        void SetScale(F32 val);

        void SetScale(F32 x, F32 y, F32 z);

        void SetOrientation(const Quaternion& quaternion);

        void SetOrientation(const EulerAngle& euler);

        void SetOrientation(const Vector& vector);

        void CalculateTransformMatrix(void);

        Vector ToWorld(const Vector& vector);

        Vector ToLocal(const Vector& vector);

        inline Vector Translate(const Vector& vector) { return _transformMatrix * vector; }

        inline Matrix Translate(const Matrix& matrix) { return _transformMatrix * matrix; }

        inline const Vector& GetPosition(void) const { return _position; }

        inline const Vector& GetScale(void) const { return _scale; }

        inline const Vector& GetForward(void) const { return _forward; }

        inline void SetForward(const Vector& axis) { _forward = axis; }

        inline void NormalizeOrientation(void) { _orientation.Normalize(); }

        inline const Quaternion& GetOrientation(void) const { return _orientation; }

        inline EulerAngle GetHumanReadableOrientation(void) const { return _orientation.GetHumanReadable(); }

        inline const Matrix& GetTransformMatrix(void) const { return _transformMatrix; }

    private:
        Matrix _transformMatrix;
        Vector _position;
        Vector _scale;
        Quaternion _orientation;
        // Z axis
        Vector _forward;
        // Y axis
        Vector _up;
        // X axis
        Vector _right;

        void _CalculateBasisVectors(F32 yaw, F32 pitch, F32 roll);

    };
};