cmake_minimum_required(VERSION 3.16)
project(sdl3test)

# set the output directory for built objects.
# This makes sure that the dynamic library goes into the build directory automatically.
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/build")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/build")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(SDL_X11_XTEST OFF)

add_subdirectory(vendored/SDL EXCLUDE_FROM_ALL)
add_subdirectory(vendored/SDL_image EXCLUDE_FROM_ALL)


# Create your game executable target as usual
add_executable(sdl3test ./src/main.c)

# Link to the actual SDL3 library.
target_link_libraries(sdl3test PRIVATE SDL3_image::SDL3_image SDL3::SDL3)
