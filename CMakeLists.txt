cmake_minimum_required(VERSION 3.17)
project(SeventyFivePercent)

set(CMAKE_CXX_STANDARD 20)

add_executable(${PROJECT_NAME} main.cpp utils/Printer.cpp utils/Printer.h game/Game.cpp game/Game.h utils/Drawer.cpp utils/Drawer.h utils/Drawable.cpp utils/Drawable.h game/Player.cpp game/Player.h game/Card.cpp game/Card.h game/Menu.cpp game/Menu.h game/Enemy.cpp game/Enemy.h)
target_link_libraries(${PROJECT_NAME} ncursesw)