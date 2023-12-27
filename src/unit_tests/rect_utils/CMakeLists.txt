cmake_minimum_required(VERSION 3.15)

add_executable(rect_utils_test main.c ../../glider_pro/RectUtils.c)
add_test(NAME rect_utils_test COMMAND $<TARGET_FILE:rect_utils_test>)
