//
// Created by marvi on 07.03.2023.
//

#include "ve_app.h"

namespace ve{

    void ve_app::run() {

        while(!veWindow.shouldClose()){
            glfwPollEvents();
        }
    }
}