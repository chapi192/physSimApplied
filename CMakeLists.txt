cmake_minimum_required(VERSION 3.24)
project(physSimApplied)

set(CMAKE_CXX_STANDARD 14)
include_directories(.)
## In most cases better set in the CMake cache
set(SFML_DIR "/usr/lib/cmake/SFML")
set(SOURCE_FILES
        Demo10.3.2022.cpp
        Dragging.cpp
        Kinematics.cpp
        Vector3d.cpp
        Vector2d.cpp)

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)
add_executable(physSim ${SOURCE_FILES})
target_link_libraries(physSim sfml-graphics sfml-window sfml-system)

