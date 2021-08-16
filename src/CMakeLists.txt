#specify the compiler
SET(CMAKE_C_COMPILER "gcc-8")
SET(CMAKE_CXX_COMPILER "g++-8")



# directory for header files 
#INCLUDE_DIRECTORIES(/usr/local/include) # gsl数学运算库的头文件所在目录。 gsl 安装时默认安装在这个位置
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/src/include) 

#添加编译器选项，两条语句都可以
SET(CMAKE_C_FLAGS -std=c99)
ADD_DEFINITIONS(-O3 -g)
ADD_DEFINITIONS(-Wno-unused-result)
ADD_DEFINITIONS(-Wall)
ADD_DEFINITIONS(-fopenmp)


#定义源文件列表
file(GLOB_RECURSE all_sources "./*.c")
#set(APP_SRC main.cpp constants.cpp IO.cpp ${SRC_gluon} ${SRC_math} ${SRC_eqn0} ${SRC_eqn_TMu} ${SRC_eqn_T0Mu})

add_executable(a ${all_sources})

#链接库
#target_link_libraries(a gomp gsl gslcblas m lapacke lapack ptf77blas atlas)
#target_link_libraries(a gomp gsl gslcblas m)
target_link_libraries(a gomp)


