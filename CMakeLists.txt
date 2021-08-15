# Print the operating system
message("operation system is ${CMAKE_SYSTEM}")

IF (WIN32)
	MESSAGE(STATUS "Now is windows")
ELSEIF (APPLE)
	MESSAGE(STATUS "Now is Apple systems.")
ELSEIF (UNIX)
	MESSAGE(STATUS "Now is UNIX-like OS's.")
ENDIF ()



cmake_minimum_required (VERSION 2.8)

# the name of the whole project
project(DSE)

# add_subdirectory(src)

