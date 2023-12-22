cmake_minimum_required(VERSION 3.15)

add_executable(glider_types_test main.c)
add_test(NAME glider_types_test COMMAND $<TARGET_FILE:glider_types_test>)
