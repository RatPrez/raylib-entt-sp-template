#pragma once
#include <raylib.h>

struct Position
{
    Vector3 value{};
};

struct Velocity
{
    Vector3 value{};
};

struct Cube
{
    Vector3 size{1.f, 1.f, 1.f};
    Color color = RED;
};
