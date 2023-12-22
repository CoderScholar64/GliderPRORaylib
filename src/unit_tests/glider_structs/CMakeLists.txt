cmake_minimum_required(VERSION 3.15)

add_executable(glider_structs_test main.c)
add_test(NAME glider_structs_test COMMAND $<TARGET_FILE:glider_structs_test>)
