cmake_minimum_required(VERSION 3.10)
project(MatrixMultiplication)


include_directories(include)


add_subdirectory(googletest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(test_multiplication test/test_matrix_multiplication.cpp)
add_executable(test_structural test/test_structural.cpp)
add_executable(test_algebraic test/test_algebraic.cpp)
add_executable(test_combinatorial test/test_combinatorial.cpp)

target_link_libraries(test_multiplication gtest gtest_main ${CMAKE_SOURCE_DIR}/lib/libmatrix_multiplication_with_errors.a)
target_link_libraries(test_structural gtest gtest_main ${CMAKE_SOURCE_DIR}/lib/libmatrix_multiplication_with_errors.a)
target_link_libraries(test_algebraic gtest gtest_main ${CMAKE_SOURCE_DIR}/lib/libmatrix_multiplication_with_errors.a)
target_link_libraries(test_combinatorial gtest gtest_main ${CMAKE_SOURCE_DIR}/lib/libmatrix_multiplication_with_errors.a)


enable_testing()


include(GoogleTest)
gtest_discover_tests(test_multiplication)
gtest_discover_tests(test_structural)
gtest_discover_tests(test_algebraic)
gtest_discover_tests(test_combinatorial)

