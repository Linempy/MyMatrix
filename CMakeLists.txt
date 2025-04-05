cmake_minimum_required(VERSION 3.30)
project(MyMatrix C)

set(CMAKE_C_STANDARD 11)

add_executable(MyMatrix main.c
        matrix/mtx_core.h
        matrix/mtx_core.c
        matrix/mtx_ops.c
        matrix/mtx_ops.h
        matrix/mtx_manipulation.c
        matrix/mtx_manipulation.h
        matrix/mtx_tasks.c
        matrix/mtx_tasks.h
)
