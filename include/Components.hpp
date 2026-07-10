#pragma once
#include <raylib.h>

struct CTransform
{
    Vector3 position{};
};

struct CVelocity
{
    Vector3 value{};
};

struct CCube
{
    Vector3 size{1.f, 1.f, 1.f};
    Color color = RED;
};
