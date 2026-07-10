#include "core/Client.hpp"
#include "Components.hpp"
#include "systems/Draw2D.hpp"
#include "systems/Draw3D.hpp"
#include "systems/Tick.hpp"

Client::Client()
{
    SetConfigFlags(FLAG_MSAA_4X_HINT | FLAG_VSYNC_HINT);
    InitWindow(1280, 720, "template-sp");
    SetTargetFPS(144);

    m_ctx.camera.position = {10.f, 10.f, 10.f};
    m_ctx.camera.target = {0.f, 0.f, 0.f};
    m_ctx.camera.up = {0.f, 1.f, 0.f};
    m_ctx.camera.fovy = 60.f;
    m_ctx.camera.projection = CAMERA_PERSPECTIVE;

    auto player = m_ctx.registry.create();
    m_ctx.registry.emplace<CTransform>(player, Vector3{0.f, 0.5f, 0.f});
    m_ctx.registry.emplace<CVelocity>(player);
    m_ctx.registry.emplace<CCube>(player);
}

Client::~Client() { CloseWindow(); }

void Client::run()
{
    while (!WindowShouldClose()) {
        m_ctx.dt = GetFrameTime();
        m_ctx.gameTime += m_ctx.dt;

        System::Tick(m_ctx);

        BeginDrawing();
        ClearBackground(Color{24, 24, 28, 255});

        BeginMode3D(m_ctx.camera);
        System::Draw3D(m_ctx);
        EndMode3D();

        System::Draw2D(m_ctx);
        EndDrawing();
    }
}
