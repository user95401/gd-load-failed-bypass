cmake_minimum_required(VERSION 3.10.0)

#curly-eureka
set(GAME_VERSION "2.206")
include($ENV{CE64_INCL})

project("my_mod")
set(developer "user95401")
set(description "mod made for gd 2.206!!! asd")
set(lib_output "C:/Geometry Dash v2.206/geode/ryzen/loadit") # post build copy

#version
set(FILEVERSION "1, 0, 0, 0")
set(LegalCopyright "user666's original")
configure_file("Version.rc" "../../../src/Version.rc")

#mod src
file(GLOB_RECURSE SRC
Src/*
#${CURLY_EUREKA_DIR}/somelib/any.cpp to include exact stuff from ce
)
add_library(${PROJECT_NAME} SHARED ${SRC} ${CURLY_EUREKA_SRC})

#POST_BUILD
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD COMMAND #POST_BUILD UPDATE USES POWERSHELL!
"${CMAKE_CURRENT_LIST_DIR}/CMakePostBuild.bat" ${developer} ${PROJECT_NAME} ${CMAKE_BINARY_DIR} ${lib_output})
