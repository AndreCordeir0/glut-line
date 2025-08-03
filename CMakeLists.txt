cmake_minimum_required(VERSION 3.10)
project(glut_test C)

set(CMAKE_C_STANDARD 99)

include_directories("C:/Program Files/JetBrains/CLion 2023.1.4/bin/mingw/include")
link_directories("C:/Program Files/JetBrains/CLion 2023.1.4/bin/mingw/lib")

add_executable(glut_test main.c)

target_link_libraries(glut_test freeglut opengl32 glu32)
