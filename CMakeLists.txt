cmake_minimum_required(VERSION 3.15)
project(glider_pro_raylib)

#find_package(raylib 3.0 REQUIRED) # Requires at least version 3.0

set(CMAKE_C_STANDARD 99) # Requires C99 standard

option(GLIDER_PRO_RAYLIB_TESTS "Enabled Tests for this project" ON)

include_directories(src/glider_pro)

#add_executable(${PROJECT_NAME} src/glider_pro/Main.c)

#target_link_libraries(${PROJECT_NAME} raylib)

if(GLIDER_PRO_RAYLIB_TESTS)
  add_subdirectory(src/unit_tests)
endif()

# Checks if OSX and links appropriate frameworks (only required on MacOS)
#if (APPLE)
#    target_link_libraries(${PROJECT_NAME} "-framework IOKit")
#    target_link_libraries(${PROJECT_NAME} "-framework Cocoa")
#    target_link_libraries(${PROJECT_NAME} "-framework OpenGL")
#endif()
