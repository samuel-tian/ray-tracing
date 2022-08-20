cmake_minimum_required(VERSION 3.10)
project(RayTracing)

find_package(OpenGL REQUIRED)

add_subdirectory(external/glfw-3.3.8)
add_subdirectory(external/glm)
add_subdirectory(external/glad)

include_directories(
	external/glfw-3.3.8/include/
	external/glm/
	external/glew-2.2.0/include
	external/glad/
	.
)

set(ALL_LIBS ${OPENGL_LIBRARY} glfw glad)

find_package(GLEW REQUIRED)
include_directories(${GLEW_INCLUDE_DIRS})
link_libraries(${GLEW_LIBRARIES})

set(HEADER_FILES
	include/ray.h
	include/solid.h
	include/sphere.h
	include/camera.h
	include/light.h
)

add_executable(RayTracing
	src/main.cpp
	src/rendering/ray.cpp
	src/rendering/camera.cpp
	src/rendering/light.cpp
	src/solids/sphere.cpp

	src/util/shader.h
	src/util/shader.cpp

	${HEADER_FILES}
)
target_include_directories(RayTracing PRIVATE include/)
target_link_libraries(RayTracing ${ALL_LIBS})
#[[
set_target_properties(RayTracing PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/src")
]]

add_executable(Test
	test/test.cpp

	${HEADER_FILES}
)
target_include_directories(Test PRIVATE include/)
target_link_libraries(Test ${ALL_LIBS})

# copy shader files to build directory
file(GLOB SHADERS
	"src/shaders/*.vs"
	"src/shaders/*.fs"
)

add_custom_command(
    TARGET RayTracing POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/src/shaders ${CMAKE_SOURCE_DIR}/build/shaders
    DEPENDS ${SHADERS})

add_custom_command(
   TARGET RayTracing POST_BUILD
   COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_CFG_INTDIR}/RayTracing${CMAKE_EXECUTABLE_SUFFIX}" "${CMAKE_CURRENT_SOURCE_DIR}/src/"
)