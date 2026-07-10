#include "systems/Draw2D.hpp"

void System::Draw2D(WorldContext &ctx)
{
    DrawFPS(10, 10);
    DrawText(TextFormat("time: %.1f", ctx.gameTime), 10, 34, 20, RAYWHITE);
}
