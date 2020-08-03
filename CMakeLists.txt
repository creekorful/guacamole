cmake_minimum_required(VERSION 3.17)
project(guacamole C)

set(CMAKE_C_STANDARD 11)

# Find ncurses library
find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

add_executable(guacamole main.c)

# Link against ncurses
target_link_libraries(guacamole ${CURSES_LIBRARIES})