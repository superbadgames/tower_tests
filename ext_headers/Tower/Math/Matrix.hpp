#pragma once

#include "pch.h"
#include "Tower/framework.h"
#include "Tower/Math/Vector.hpp"
#include "Tower/Math/Quaternion.hpp"


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

        ~Matrix(void);

        Matrix& operator=(const Matrix& copy);

        Matrix operator*(F32 val);

        Vector operator*(const Vector& other);

        Matrix operator*(const Matrix& other);

        Matrix& operator*=(const Matrix& other);

        void Transpose(void);

        void MakeOrthographic(F32 screenWidth, F32 screenHeight, F32 viewDistance);

        void MakePerspective(F32 fieldOfView, F32 aspectRation, F32 viewDistance);

        void MakeIdentity(F32 val = 1.0f);

        // TODO: Make sure these terms are correct
        // Translate = change this matrix so that it will now transform other things to this position
        void Translate(const Vector& vector);

        void Rotate(const Quaternion& quaternion);

        void Scale(const Vector& scale);

        static Matrix CreateTranslationMatrix(const Vector vector);

        void LookAt(const Vector& position, const Vector& target, const Vector& up);

        static Matrix CreateLookAtMatrix(const Vector& position, const Vector& target, const Vector& up);

        // TODO: Can this be optimized?
        Matrix GetInverse(void);

        void Inverse(void);

        inline const F32* GetRaw(void) const { return _matrix; }

        // Matrix accessors
        inline void SetX1(F32 val) { _matrix[X1] = val; }
        inline void SetX2(F32 val) { _matrix[X2] = val; }
        inline void SetX3(F32 val) { _matrix[X3] = val; }
        inline void SetX4(F32 val) { _matrix[X4] = val; }

        inline void SetY1(F32 val) { _matrix[Y1] = val; }
        inline void SetY2(F32 val) { _matrix[Y2] = val; }
        inline void SetY3(F32 val) { _matrix[Y3] = val; }
        inline void SetY4(F32 val) { _matrix[Y4] = val; }

        inline void SetZ1(F32 val) { _matrix[Z1] = val; }
        inline void SetZ2(F32 val) { _matrix[Z2] = val; }
        inline void SetZ3(F32 val) { _matrix[Z3] = val; }
        inline void SetZ4(F32 val) { _matrix[Z4] = val; }

        inline void SetW1(F32 val) { _matrix[W1] = val; }
        inline void SetW2(F32 val) { _matrix[W2] = val; }
        inline void SetW3(F32 val) { _matrix[W3] = val; }
        inline void SetW4(F32 val) { _matrix[W4] = val; }

        inline F32 GetX1(void) { return _matrix[X1]; }
        inline F32 GetX2(void) { return _matrix[X2]; }
        inline F32 GetX3(void) { return _matrix[X3]; }
        inline F32 GetX4(void) { return _matrix[X4]; }

        inline F32 GetY1(void) { return _matrix[Y1]; }
        inline F32 GetY2(void) { return _matrix[Y2]; }
        inline F32 GetY3(void) { return _matrix[Y3]; }
        inline F32 GetY4(void) { return _matrix[Y4]; }

        inline F32 GetZ1(void) { return _matrix[Z1]; }
        inline F32 GetZ2(void) { return _matrix[Z2]; }
        inline F32 GetZ3(void) { return _matrix[Z3]; }
        inline F32 GetZ4(void) { return _matrix[Z4]; }

        inline F32 GetW1(void) { return _matrix[W1]; }
        inline F32 GetW2(void) { return _matrix[W2]; }
        inline F32 GetW3(void) { return _matrix[W3]; }
        inline F32 GetW4(void) { return _matrix[W4]; }

    private:
        // Helper access consts
        const U8 X1 = 0;
        const U8 X2 = 1;
        const U8 X3 = 2;
        const U8 X4 = 3;

        const U8 Y1 = 4;
        const U8 Y2 = 5;
        const U8 Y3 = 6;
        const U8 Y4 = 7;

        const U8 Z1 = 8;
        const U8 Z2 = 9;
        const U8 Z3 = 10;
        const U8 Z4 = 11;

        const U8 W1 = 12;
        const U8 W2 = 13;
        const U8 W3 = 14;
        const U8 W4 = 15;

        F32 _matrix[16];
    };
}