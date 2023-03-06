cmake_minimum_required(VERSION 3.24)
project(VulkanEngine)

set(CMAKE_CXX_STANDARD 17)

add_executable(VulkanEngine main.cpp)


# Disable Building Test for GLFW
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

# Add root dir for GLFW
add_subdirectory(/users/marvi/Documents/Visual\ Studio\ 2022/Libraries/glfw-3.3.8 build)
add_library(glfw /users/marvi/Documents/Visual\ Studio\ 2022/Libraries/glfw-3.3.8)

target_link_libraries(VulkanEngine glfw)
target_include_directories(glfw /users/marvi/Documents/Visual\ Studio\ 2022/Libraries/glfw-3.3.8/include)

include_directories(C:/VulkanSDK/1.3.239.0/Include)
include_directories(/users/marvi/Documents/Visual\ Studio\ 2022/Libraries/glm)

link_directories(C:/VulkanSDK/1.3.239.0/Lib)
link_directories(/users/marvi/Documents/Visual\ Studio\ 2022/Libraries/glfw-3.3.8/lib-vc2022)

