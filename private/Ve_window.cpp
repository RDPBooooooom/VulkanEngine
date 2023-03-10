//
// Created by marvi on 07.03.2023.
//
#include <stdexcept>
#include "Ve_window.h"

namespace ve {
    VeWindow::VeWindow(int w, int h, std::string name) : width{w}, height{h}, windowName{name} {
        initWindow();
    }

    VeWindow::~VeWindow() {
        glfwDestroyWindow(window);
        glfwTerminate();
    }

    void VeWindow::initWindow() {
        glfwInit();
        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
        glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

        window = glfwCreateWindow(width, height, windowName.c_str(), nullptr, nullptr);
    }

    bool VeWindow::shouldClose() {
        return glfwWindowShouldClose(window);
    }

    void VeWindow::createWindowSurface(VkInstance instance, VkSurfaceKHR *surface) {
        if(glfwCreateWindowSurface(instance, window, nullptr, surface) != VK_SUCCESS){
            throw std::runtime_error("Failed to create window surface");
        }
    }
}