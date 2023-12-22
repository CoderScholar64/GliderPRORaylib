cmake_minimum_required(VERSION 3.15)

add_executable(string_utils_test ../../glider_pro/StringUtils.c main.c)
add_test(NAME string_utils_test COMMAND $<TARGET_FILE:string_utils_test>)
