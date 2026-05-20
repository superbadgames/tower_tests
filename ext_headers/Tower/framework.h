#pragma once

#ifdef TOWER_EXPORTS
#define TOWER_API __declspec(dllexport)
#else
#define TOWER_API __declspec(dllimport)
#endif

extern "C" {
#include <glad/glad.h>
#include <GLFW/glfw3.h>
}


// stl global includes
// stl library with signed integer types with exact widths
#include <cstdint>
// stl library with memory utils. Tower uses shared_ptr and unique_ptr
#include <memory>
#include <string>
#include <cassert>

using std::shared_ptr;
using std::unique_ptr;
using std::string;

// Custom typedefs
typedef int8_t S8;
typedef int16_t S16;
typedef int32_t S32;
typedef int64_t S64;
typedef uint8_t U8;
typedef uint16_t U16;
typedef uint32_t U32;
typedef uint64_t U64;
typedef float F32;
typedef double F64;


const F32 PI = static_cast<F32>(3.14159265358979); // or 180 degrees
const F32 TWO_PI = 2.0f * PI; // or 360 degrees
const F32 PI_OVER_TWO = PI / 2.0f; // or 90 degrees
const F32 _90Degrees = PI_OVER_TWO;
const F32 _180Degrees = PI;
const F32 _360Degrees = TWO_PI;

//==========================================================================================================================
// Global Helper functions
//==========================================================================================================================
inline F32 SQR(F32 x)
{
    return x * x;
}

inline F32 RADIAN(F32 angle)
{
    return static_cast<F32>(angle * PI / 180.0f);
}

inline F32 DEGREE(F32 radian)
{
    return static_cast<F32>(radian * 180.0f / PI);
}

inline F32 CLAMP(F32 val, F32 min, F32 max)
{
    if (val < min)
    {
        return min;
    }
    else if (val > max)
    {
        return max;
    }
    else
    {
        return val;
    }
}