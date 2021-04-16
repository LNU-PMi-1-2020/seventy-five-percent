cmake_minimum_required(VERSION 3.17)
project(SeventyFivePercent)

set(CMAKE_CXX_STANDARD 20)

file(GLOB SOURCE_FILES
        "utils/*.h"
        "utils/*.cpp"
        "game/*.h"
        "game/*.cpp"
        )

add_executable(${PROJECT_NAME} main.cpp ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} ncursesw)