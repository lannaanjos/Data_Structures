cmake_minimum_required(VERSION 4.1)
project(Data_Structures C)

set(CMAKE_C_STANDARD 99)

add_executable(Data_Structures
        main.c
)

target_include_directories(Data_Structures PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/Exercises
)
