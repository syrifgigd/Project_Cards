cmake_minimum_required(VERSION 3.23)

set(project "cardss")
project(${project})

set(CMAKE_CXX_STANDARD 17)

set(${project}_SOURCES
    cards.cpp
    ImageCard.cpp
    menu.cpp
    TextCard.cpp)

set(${project}_HEADERS
    cards.h
    ImageCard.h
    menu.h
    TextCard.h
    json.hpp)

set(${project}_SOURCE_LIST
    ${${project}_SOURCES}
    ${${project}_HEADERS})

add_library(${project}
    STATIC
    ${${project}_SOURCE_LIST})