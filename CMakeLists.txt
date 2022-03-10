cmake_minimum_required (VERSION 3.0)
project (NumericalOptimization)
 
find_package (Eigen3 3.4 REQUIRED NO_MODULE)
 
file(GLOB_RECURSE SOURCE_FILES CONFIGURE_DEPENDS *.cpp *.h)

add_executable(NumericalOptimization ${SOURCE_FILES})
target_link_libraries (Eigen3::Eigen)