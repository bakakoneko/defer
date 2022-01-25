cmake_minimum_required(VERSION 3.22)
project(defer)

set(CMAKE_CXX_STANDARD 23)

add_library(defer INTERFACE)
target_include_directories(defer INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/include")

if (DEFER_BUILD_TESTING)
    add_subdirectory(test)
endif ()

export(TARGETS defer NAMESPACE defer:: FILE defer-targets.cmake)
