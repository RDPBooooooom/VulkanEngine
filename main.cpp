#include <iostream>
#include "private/ve_app.h"

int main() {

    ve::ve_app app{};

    try {
        app.run();
    } catch (const std::exception &e){
        std::cerr << e.what() << '\n';
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}