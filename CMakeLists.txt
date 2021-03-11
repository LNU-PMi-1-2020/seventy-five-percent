cmake_minimum_required(VERSION 3.17)
project(SeventyFivePercent)

set(CMAKE_CXX_STANDARD 20)

add_executable(${PROJECT_NAME} main.cpp utils/Printer.cpp utils/Printer.h)
target_link_libraries(${PROJECT_NAME} ncursesw)