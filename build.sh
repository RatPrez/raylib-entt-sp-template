#!/usr/bin/env bash
set -e
ROOT="$(cd "$(dirname "$0")" && pwd)"
BUILD_DIR="$ROOT/build"

cmake -B "$BUILD_DIR" -S "$ROOT" -DCMAKE_BUILD_TYPE=Debug
cmake --build "$BUILD_DIR" -- -j"$(nproc)"

ln -sf build/compile_commands.json "$ROOT/compile_commands.json"

echo ""
echo "Build complete: $BUILD_DIR/client"
