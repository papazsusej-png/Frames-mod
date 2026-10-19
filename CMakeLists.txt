cmake_minimum_required(VERSION 3.21)

project(MyFrameFixer VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Geode REQUIRED)

add_geode_mod(MyFrameFixer
    SOURCES
        src/main.cpp
)

target_link_libraries(MyFrameFixer PRIVATE Geode::Geode)
