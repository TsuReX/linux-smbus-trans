cmake_minimum_required(VERSION 2.8)

message("-- MSG: Add dir ${CMAKE_CURRENT_SOURCE_DIR}")

set(PROJ_NAME linux-smbus-trans)

project(${PROJ_NAME} C)

set(CMAKE_C_FLAGS "-Wall -Werror")

set(C_SRC	"main.c"
			${EXTRA_SRC})

add_executable(${PROJ_NAME}  ${C_SRC})

target_link_libraries(${PROJ_NAME})