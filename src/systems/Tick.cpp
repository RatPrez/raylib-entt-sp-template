#include "systems/Tick.hpp"
#include "Components.hpp"

void System::Tick(WorldContext &ctx)
{
    auto view = ctx.registry.view<Position, Velocity>();
    for (auto [entity, position, velocity] : view.each()) {
        velocity.value = {0.f, 0.f, 0.f};
        if (IsKeyDown(KEY_W)) {
            velocity.value.z -= 5.f;
        }
        if (IsKeyDown(KEY_S)) {
            velocity.value.z += 5.f;
        }
        if (IsKeyDown(KEY_A)) {
            velocity.value.x -= 5.f;
        }
        if (IsKeyDown(KEY_D)) {
            velocity.value.x += 5.f;
        }

        position.value.x += velocity.value.x * ctx.dt;
        position.value.y += velocity.value.y * ctx.dt;
        position.value.z += velocity.value.z * ctx.dt;
    }

    UpdateCamera(&ctx.camera, CAMERA_ORBITAL);
}
