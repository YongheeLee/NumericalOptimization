cmake_minimum_required (VERSION 3.0)
project (Optimization)
 
find_package (Eigen3 3.4 REQUIRED NO_MODULE)
 
file(GLOB SOURCE_FILES *.cpp *.h)

add_executable(Optimization ${SOURCE_FILES})
target_link_libraries (Optimization Eigen3::Eigen)
