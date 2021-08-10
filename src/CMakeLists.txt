#指定编译器
SET(CMAKE_C_COMPILER "gcc")
SET(CMAKE_CXX_COMPILER "g++")



# directory for header files | 头文件目录
#INCLUDE_DIRECTORIES(/usr/local/include) # gsl数学运算库的头文件所在目录。 gsl 安装时默认安装在这个位置
#INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/include) # 也可以选择将头文件拷贝出来放在项目的文件夹内。这一条语句和上一条语句任选其一即可。

#添加编译器选项，两条语句都可以
SET(CMAKE_C_FLAGS -std=c99)
ADD_DEFINITIONS(-O3 -g -fopenmp)
ADD_DEFINITIONS(-Wno-unused-result)
ADD_DEFINITIONS(-Wall)


#定义源文件列表
set(APP_SRC main.cpp )
#set(APP_SRC main.cpp constants.cpp IO.cpp ${SRC_gluon} ${SRC_math} ${SRC_eqn0} ${SRC_eqn_TMu} ${SRC_eqn_T0Mu})
#set(APP_SRC main.c constants.c ${SRC_IO} ${SRC_math} ${SRC_gluon} ${SRC_eqn_T0Mu} ${SRC_eqn_T0Mu_Cartesian} ${SRC_eqn_T0Mu_polar} ${SRC_eqn_TMu} ${SRC_eqn_T0Mu0} ${SRC_properties} ${SRC_NeutronStar} ${SRC_RMF} ${SRC_Construction} ${SRC_SigmaTerm} ${SRC_condense} ${SRC_NS} ${SRC_Tc} ${SRC_nq} ${SRC_TGL})

add_executable(a ${APP_SRC})

#链接库
#target_link_libraries(a gomp gsl gslcblas m lapacke lapack ptf77blas atlas)
#target_link_libraries(a gomp gsl gslcblas m)
