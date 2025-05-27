cmake_minimum_required(VERSION 3.20)
project(MyProject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Источники и заголовки
set(SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
)

set(HEADERS
    ${CMAKE_CURRENT_SOURCE_DIR}/cardss/cards.h
    ${CMAKE_CURRENT_SOURCE_DIR}/cardss/ImageCard.h
    ${CMAKE_CURRENT_SOURCE_DIR}/cardss/menu.h
    ${CMAKE_CURRENT_SOURCE_DIR}/cardss/TextCard.h
    ${CMAKE_CURRENT_SOURCE_DIR}/cardss/json.hpp
)

# Создание исполняемого файла
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

# Добавление подкаталога cardss
add_subdirectory(cardss)

# Настройка путей включения
target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/cardss
)
# Связывание библиотек
target_link_libraries(${PROJECT_NAME} PRIVATE cardss)