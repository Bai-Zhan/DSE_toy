#specify the compiler
SET(CMAKE_C_COMPILER "gcc")
SET(CMAKE_CXX_COMPILER "g++")


# directory for header files 
#INCLUDE_DIRECTORIES(/usr/local/include) # gsl数学运算库的头文件所在目录。 gsl 安装时默认安装在这个位置
#INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/include) # 也可以选择将头文件拷贝出来放在项目的文件夹内。这一条语句和上一条语句任选其一即可。

#添加编译器选项，两条语句都可以
SET(CMAKE_C_FLAGS -std=c99)
ADD_DEFINITIONS(-O3 -g -fopenmp)
ADD_DEFINITIONS(-Wno-unused-result)
ADD_DEFINITIONS(-Wall)


#定义源文件列表
file(GLOB_RECURSE all_sources "./*.c")
#set(APP_SRC main.cpp constants.cpp IO.cpp ${SRC_gluon} ${SRC_math} ${SRC_eqn0} ${SRC_eqn_TMu} ${SRC_eqn_T0Mu})

add_executable(a ${all_sources})

#链接库
#target_link_libraries(a gomp gsl gslcblas m lapacke lapack ptf77blas atlas)
#target_link_libraries(a gomp gsl gslcblas m)

target_include_directories(a PRIVATE ${PROJECT_SOURCE_DIR}/src/include) # The path for the .h files written by ourselves.

