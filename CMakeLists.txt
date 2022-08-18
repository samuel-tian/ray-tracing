cmake_minimum_required(VERSION 3.10)
project(RayTracing)

find_package(OpenGL REQUIRED)

add_subdirectory(external/glfw-3.3.8)

include_directories(
	external/glfw-3.3.8/include/
	.
)

set(ALL_LIBS
	${OPENGL_LIBRARY}
	glfw
)

add_executable(RayTracing
	src/tmp.cpp
)
target_link_libraries(RayTracing
	${ALL_LIBS}
)