//
// Created by marvi on 07.03.2023.
//

#ifndef VULKANENGINE_VE_APP_H
#define VULKANENGINE_VE_APP_H

#include "Ve_window.h"

namespace ve{

    class ve_app {

    public:
        static constexpr int WIDTH = 800;
        static constexpr int HEIGHT = 600;

        void run();
    private:
        VeWindow veWindow{WIDTH, HEIGHT, "Hello Vulkan!"};

    };
}


#endif //VULKANENGINE_VE_APP_H
