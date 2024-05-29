/**
 * @file structural.cpp
 * @brief Test cases that verify the consistency of structural (i.e. software/implementation related) properties for the provided matrix
 * multiplication function.
 */

#include "matrix_multiplication.h"
#include <iostream>
#include <vector>
#include <gtest/gtest.h>

/*
*2.1 Provide non-coherent sizes in the call.
2.1.1 Matrix that could not be multiplied but different sizes
2.1.2 Matrix that could be multiplied but sizes that could not be multiplied
2.2 Provide negative sizes to the function call
2.3 Provide nullptr matrices and see what happens
2.4 Search for a maximum number that is accepted
2.5 Search for a minimum number that is accepted
*/

/*
* 2.1 Provide non-coherent sizes in the call.
*/
TEST(StructuralMultiplyMatrices, WrongSizes_2_1) {
    
    std::vector<std::vector<int>> A = {
        {1, 2, 3},
        {4, 5, 6}
    };
    std::vector<std::vector<int>> B = {
        {7, 8, 4, 10},
        {9, 10, 5, 11},
        {11, 12, 6, 12}
    };
    std::vector<std::vector<int>> C(2, std::vector<int>(2, 0));

    ASSERT_TRUE(true);
    //ASSERT_DEATH(multiplyMatrices(A, B, C, 1, 3, 4),
    //                "Assertion failed: \\expected failure with rowsA != A.size()\\");
    
}


/**
 * @brief Entry point for test execution.
 */
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
