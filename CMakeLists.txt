cmake_minimum_required(VERSION 3.30)
project(MyMatrix C)

set(CMAKE_C_STANDARD 11)

add_executable(MyMatrix main.c
        matrix/initMtx.h
        matrix/initMtx.c
        matrix/operations.c
        matrix/operations.h
        matrix/manipulation.c
        matrix/manipulation.h
        matrix/tasks.c
        matrix/tasks.h
)
