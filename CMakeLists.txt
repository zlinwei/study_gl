cmake_minimum_required(VERSION 3.16)
project(study_gl)

set(CMAKE_CXX_STANDARD 14)

find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIR})
message(STATUS "${OpenGL_FOUND}")
set(DEPS ${DEPS} ${OPENGL_LIBRARIES})

find_package(GLEW REQUIRED)
include_directories(${GLEW_INCLUDE_DIR})
message(STATUS "GLEW Found:${GLEW_SHARED_FOUND} VERSION: ${GLEW_VERSION}")
set(DEPS ${DEPS} ${GLEW_LIBRARIES})

find_package(glfw3 3 REQUIRED)
message(STATUS "${glfw3_FOUND} VERSION:${glfw3_VERSION}")
set(DEPS ${DEPS} glfw)

find_package(glog CONFIG REQUIRED)
set(DEPS ${DEPS} glog::glog)

# soil
#include_directories(third_party/soil/inc)
#add_subdirectory(third_party/soil_local)

set(DEPS ${DEPS} SOIL)


#get_cmake_property(_variableNames VARIABLES)
#list(SORT _variableNames)
#foreach (_variableName ${_variableNames})
#    message(STATUS "${_variableName}=${${_variableName}}")
#endforeach ()

add_subdirectory(a_basic)