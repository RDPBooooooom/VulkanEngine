//
// Created by marvi on 07.03.2023.
//

#ifndef VULKANENGINE_VE_WINDOW_H
#define VULKANENGINE_VE_WINDOW_H

#include <string>
#include "GLFW/glfw3.h"

namespace ve {

    class VeWindow {

    public:
        VeWindow(int w, int h, std::string name);
        ~VeWindow();

        VeWindow(const VeWindow &) = delete;
        VeWindow &operator=(const VeWindow &) = delete;

        bool shouldClose();

    private:

        void initWindow();

        const int width;
        const int height;

        std::string windowName;
        GLFWwindow *window;

    };


}


#endif //VULKANENGINE_VE_WINDOW_H
