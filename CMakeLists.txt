cmake_minimum_required(VERSION 3.24)
project(VulkanEngine)

set(CMAKE_CXX_STANDARD 17)

add_executable(${PROJECT_NAME} main.cpp)

#           DOWNLOAD ALL THE SUBMODULES
find_package(Git QUIET)
if(GIT_FOUND AND EXISTS "${PROJECT_SOURCE_DIR}/.git")
#Update submodules as needed
    option(GIT_SUBMODULE "Check submodules during build" ON)
    if(GIT_SUBMODULE)
        message(STATUS "Submodule update")
        execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive
                        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
                        RESULT_VARIABLE GIT_SUBMODULE_RESULT)
        if(NOT GIT_SUBMODULE_RESULT EQUAL "0")
            message(FATAL_ERROR "git submodule update --init failed with ${GIT_SUBMODULE_RESULT}, please checkout")
        endif()
    endif()
endif()

# Disable Building Tests for GLFW
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

if(NOT EXISTS "${PROJECT_SOURCE_DIR}/external/glfw/CMakeLists.txt")
    message(FATAL_ERROR "The glfw submodule was not downloaded! GIT_SUBMODULE was turned off or failed.")
ENDIF()

target_include_directories(${PROJECT_NAME} PUBLIC external/glfw/include)

target_link_directories(${PROJECT_NAME} PRIVATE external/glfw/src)

target_link_libraries(${PROJECT_NAME} glfw)

#include_directories(C:/VulkanSDK/1.3.239.0/Include)
#include_directories(/users/marvi/Documents/Visual\ Studio\ 2022/Libraries/glm)

#link_directories(C:/VulkanSDK/1.3.239.0/Lib)
