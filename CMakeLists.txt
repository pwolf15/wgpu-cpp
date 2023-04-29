cmake_minimum_required(VERSION 3.0)

project(webgpu)

add_subdirectory(glfw)

add_executable(main main.cpp)
set_target_properties(main PROPERTIES
    CXX_STANDARD 17
    COMPILE_WARNING_AS_ERROR ON
)
target_link_libraries(main PRIVATE glfw)