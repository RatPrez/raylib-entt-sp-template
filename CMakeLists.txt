cmake_minimum_required(VERSION 3.16)
project(template_sp CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(FetchContent)

FetchContent_Declare(
    raylib
    GIT_REPOSITORY https://github.com/raysan5/raylib.git
    GIT_TAG        5.5
)
FetchContent_MakeAvailable(raylib)

FetchContent_Declare(
    entt
    GIT_REPOSITORY https://github.com/skypjack/entt.git
    GIT_TAG        v3.15.0
)
FetchContent_MakeAvailable(entt)

file(GLOB_RECURSE CLIENT_SOURCES src/*.cpp)

add_executable(client ${CLIENT_SOURCES})

target_include_directories(client PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(client PRIVATE
    raylib
    EnTT::EnTT)
