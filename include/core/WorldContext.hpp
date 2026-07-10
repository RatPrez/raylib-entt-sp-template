#pragma once
#include <entt/entt.hpp>
#include <raylib.h>

struct WorldContext
{
    entt::registry registry;
    Camera3D camera{};
    float gameTime = 0.f;
    float dt = 0.f;
};
