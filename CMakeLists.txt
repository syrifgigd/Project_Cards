cmake_minimum_required(VERSION 3.20)
project(Cards) # <- project name

set(SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/cards/cards.cpp
)
set(HEADERS
    ${CMAKE_CURRENT_SOURCE_DIR}/cards/cards.h
)
add_executable(${CMAKE_PROJECT_NAME} ${SOURCES} ${HEADERS})
add_subdirectory(cards)

target_link_libraries(${project} cards)
