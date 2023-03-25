
cmake_minimum_required(VERSION 3.5)

project(Battle_Space)

find_package(Qt5 COMPONENTS Core Gui Widgets REQUIRED)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)


qt5_add_resources(RESOURCES Resources.qrc)

find_package(Qt5 COMPONENTS Core Gui Widgets REQUIRED)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

add_executable(Battle_Space main.cpp Player.cpp Player.h Bullet.cpp Bullet.h Dificulties_Window.cpp Dificulties_Window.h Easy_game.cpp Easy_game.h Hard_Game.cpp Hard_Game.h Normal_Game.cpp Normal_Game.h Resources.qrc Enemy_1.cpp Enemy_1.h Enemy_2.cpp Enemy_2.h)

target_link_libraries(Battle_Space Qt5::Core Qt5::Gui Qt5::Widgets)

target_link_libraries(Battle_Space Qt5::Core Qt5::Gui Qt5::Widgets)

set(CMAKE_AUTOMOC_FLAGS "-fskip-targets=MOC_AUTOMOC_TARGETS_REGEX")

