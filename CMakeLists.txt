cmake_minimum_required(VERSION 3.10)
project(RayTracing)

find_package(OpenGL REQUIRED)

add_subdirectory(external/glfw-3.3.8)
add_subdirectory(external/glm)

include_directories(
	external/glfw-3.3.8/include/
	external/glm/
	.
)

set(ALL_LIBS ${OPENGL_LIBRARY} glfw)

set(HEADER_FILES
	include/ray.h
	include/solid.h
	include/sphere.h
)

add_executable(RayTracing
	src/main.cpp
	src/ray.cpp
	src/solids/sphere.cpp
	${HEADER_FILES}
)
target_include_directories(RayTracing PRIVATE include/)
target_link_libraries(RayTracing ${ALL_LIBS})

add_executable(Test
	test/test.cpp
	src/ray.cpp
	src/solids/sphere.cpp
	${HEADER_FILES}
)
target_include_directories(Test PRIVATE include/)
target_link_libraries(Test ${ALL_LIBS})