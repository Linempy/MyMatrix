cmake_minimum_required(VERSION 3.30)
project(MyMatrix C)

set(CMAKE_C_STANDARD 11)

add_executable(MyMatrix main.c
        matrix/matrix.h
        matrix/matrix.c
        lexicon/lexicon.h
        lexicon/lexicon.c
)
