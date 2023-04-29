#include <iostream>
#include <GLFW/glfw3.h>

#include "webgpu/webgpu.h"

#ifdef WEBGPU_BACKEND_WGPU
#include <webgpu/wgpu.h>
#define wgpuInstanceRelease wgpuInstanceDrop
#endif

int main()
{
    if (!glfwInit())
    {
        std::cerr << "Could not initialize GLFW!" << std::endl;
        return 1;
    }
    GLFWwindow* window = glfwCreateWindow(640, 480, "Learn WebGPU", NULL, NULL);
    if (!window)
    {
        std::cerr << "Could not open window!" << std::endl;
        glfwTerminate();
        return 1;
    }

    // create descriptor
    WGPUInstanceDescriptor desc = {};
    desc.nextInChain = nullptr;

    // create instance using descriptor
    WGPUInstance instance = wgpuCreateInstance(&desc);
    if (!instance) 
    {
        std::cerr << "Could not initialize WebGPU" << std::endl;
        return 1;
    }

    std::cout << "WGPU instance: " << instance << std::endl;

    std::cout << "Hello world" << std::endl;

    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
    }

    wgpuInstanceRelease(instance);
    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}