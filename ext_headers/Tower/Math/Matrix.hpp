#pragma once

#include "pch.h"
#include "Tower/framework.h"
#include "Tower/Math/Vector.hpp"
#include "Tower/Math/Quaternion.hpp"
#include <glm/mat4x4.hpp>

namespace Tower
{
    class Matrix;
    typedef shared_ptr<Matrix> p_Matrix;

    // Forward declaration
    class Quaternion;

    class Matrix
    {
    public:
        Matrix(void);

        Matrix(const Matrix& copy);

        Matrix(F32 value);

        Matrix(F32 x1, F32 x2, F32 x3, F32 x4,
               F32 y1, F32 y2, F32 y3, F32 y4,
               F32 z1, F32 z2, F32 z3, F32 z4,
               F32 w1, F32 w2, F32 w3, F32 w4);

        ~Matrix(void);

        Matrix& operator=(const Matrix& copy);

        Matrix operator+(const Matrix& other);

        Matrix& operator+=(const Matrix& other);

        Matrix operator-(const Matrix& other);

        Matrix& operator-=(const Matrix& other);

        Matrix operator*(const Matrix& other);

        Vector operator*(const Vector& other);

        Matrix& operator*=(const Matrix& other);

        void MakeOrthographic(F32 screenWidth, F32 screenHeight, F32 viewDistance);

        void MakePerspective(F32 fieldOfView, F32 aspectRation, F32 viewDistance);

        void SetPosition(const Vector& vector);

        void SetOrientation(const Quaternion& quaternion);

        void SetScale(const Vector& scale);

        static Matrix CreateTranslationMatrix(const Vector vector);

        void LookAt(const Vector& position, const Vector& target, const Vector& up);

        static Matrix CreateLookAtMatrix(const Vector& position, const Vector& target, const Vector& up);

        F32 Determinant(void);

        Matrix GetInverse(void);

        void Transpose(void);

        void MakeIdentity(void);

        inline void Inverse(void) { _matrix = glm::inverse(_matrix); }

        inline void Set(const glm::mat4& matrix) { _matrix = matrix; }

        inline const glm::mat4& GetRaw(void) const { return _matrix; }

    private:
        glm::mat4 _matrix;
    };
}