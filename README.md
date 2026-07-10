# template-sp

Personal singleplayer game template. raylib + EnTT.

## Usage

```
./build.sh   # or build.bat on Windows
./run.sh     # or run.bat
```

First build fetches raylib and EnTT, so it takes a minute. `compile_commands.json` is symlinked to the project root for the IDE.

## Layout

- `include/core/` — `Client` (game loop) and `WorldContext` (registry, camera, passed into every system)
- `include/Components.hpp` — components
- `include/systems/` + `src/systems/` — `Tick`, `Draw3D`, `Draw2D`

Add a system: header in `include/systems/`, source in `src/systems/`, call it from `Client::run()`.
