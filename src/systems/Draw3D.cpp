#include "systems/Draw3D.hpp"
#include "Components.hpp"

void System::Draw3D(WorldContext &ctx)
{
    DrawGrid(20, 1.f);

    auto view = ctx.registry.view<Position, Cube>();
    for (auto [entity, position, cube] : view.each()) {
        DrawCubeV(position.value, cube.size, cube.color);
        DrawCubeWiresV(position.value, cube.size, BLACK);
    }
}
