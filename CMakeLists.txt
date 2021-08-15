# Print the operating system
message("operation system is ${CMAKE_SYSTEM}")

IF (WIN32)
	MESSAGE(STATUS "Now is windows")
ELSEIF (APPLE)
	MESSAGE(STATUS "Now is Apple systems.")
ELSEIF (UNIX)
	MESSAGE(STATUS "Now is UNIX-like OS's.")
ENDIF ()



cmake_minimum_required (VERSION 3.10.2)

project(DSE) # the name of the whole project
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}) # The executable file will be generated in the top of the building folder.

add_subdirectory(src) 

