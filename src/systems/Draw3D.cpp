#include "systems/Draw3D.hpp"
#include "Components.hpp"

void System::Draw3D(WorldContext &ctx)
{
    DrawGrid(20, 1.f);

    auto view = ctx.registry.view<CTransform, CCube>();
    for (auto [entity, transform, cube] : view.each()) {
        DrawCubeV(transform.position, cube.size, cube.color);
        DrawCubeWiresV(transform.position, cube.size, BLACK);
    }
}
