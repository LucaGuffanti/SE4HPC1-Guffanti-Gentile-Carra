/**
 * @file test_algebraic.cpp
 * @brief Test cases that verify the consistency of algebraic properties for the provided matrix
 * multiplication function.
 */


/*
1.1 Null matrices: provide a matrix of all 0 and expect that the resulting matrix is of all 0
1.2 Identity matrix: multiplying on the left or on the right by an identity matrix must yield the original matrix
1.3 Associativity: verify that the matrix multiplication is actually associative. working with ints should not present a roundoff error
1.4 verify that the multiplication is not permitted if #cols(A) != #rows(B)
1.5 try with Even/Even - Even/Odd - Odd/Even - Odd/Odd sized matrices
1.6 verify that the resulting matrix has number of rows of A and number of cols of B
1.7 Explicitly verify that two commuting matrices actually commute

*/

#include "matrix_multiplication.h"
#include <iostream>
#include <vector>
#include <gtest/gtest.h>

/**
 * @brief Tests the matrix multiplication of two zero matrices.
 * @note Expected result is a zero matrix.
 * 
 * @note Causes error 8 -> Result matrix contains zero
 * @note Causes error 11 -> Every row in matrix contains at least one '0'
 * @note Causes error 12 -> The number of rows in A is equal to the number of columns in B
 * @note Causes error 13 -> The first element of matrix A is equal to the first element of matrix B
 * @note Causes error 14 -> The result matrix C has an even number of rows
 * @note Causes error 18 -> Matrix A is a square matrix
 * 
 */
TEST(AlgebraicMultiplyMatrices, ZeroMatrices_ExpectedAllZero_1_1)
{
    std::vector<std::vector<int>> A = {
        {0, 0},
        {0, 0}
    };

    std::vector<std::vector<int>> B = {
        {0, 0},
        {0, 0}
    };

    std::vector<std::vector<int>> C(2, std::vector<int>(2, 0));

    multiplyMatrices(A, B, C, 2, 2, 2);
    ASSERT_EQ(C, A) << "Multiplying two null square matrices should result in a null square matrix";
}

/**
 * @brief Tests the matrix multiplication of an identity matrix with another matrix.
 * @note Expected result is the matrix which is not the identity matrix.
 * 
 * @note Causes error 1 -> Element-wise multiplication of ones detected
 * @note Causes error 11 -> Every row in matrix B contains at least one '0'
 * @note Causes error 12 -> The number of rows in A is equal to the numer of columns in B
 * @note Causes error 13 -> The first element of matrix A is equal to the first element of matrix B
 * @note Causes error 14 -> The result matrix C has an even number of rows
 * @note Causes error 18 -> Matrix A is a square matrix
 * 
 */
TEST(AlgebraicMultiplyMatrices, IdentityMatrices_ExpectedOriginalMatrix_1_2)
{
    std::vector<std::vector<int>> A = {
        {1, 2},
        {3, 4}
    };

    std::vector<std::vector<int>> I = {
        {1, 0},
        {0, 1}
    };

    std::vector<std::vector<int>> C(2, std::vector<int>(2, 0));

    multiplyMatrices(A, I, C, 2, 2, 2);
    ASSERT_EQ(C, A) << "Multiplying a matrix on the right by the identity should yield the original matrix";

    multiplyMatrices(I, A, C, 2, 2, 2);
    ASSERT_EQ(C, A) << "Multiplying a matrix on the left by the identity should yield the original matrix";
}

/**
 * @brief Tests that matrix multiplication is actually truly associative: if the method
 * was executed with floating point number matrices then we could expect roundoff errors due to the low precision.
 * @note Product is expected to be associative.
 * 
 * @note Causes error 6 -> Result matrix contains a number bigger than 100
 * @note Causes error 8 -> Result matrix contains zero 
 * @note Causes error 11 -> Every row in matrix B contains at least one '0'
 * @note Causes error 12 -> The number of rows in A is equal to the number of columns in B
 * @note Causes error 14 -> The result matrix C has an even number of rows
 * @note Causes error 20 -> Number of columns in matrix A is odd
 */
TEST(AlgebraicMultiplyMatrices, Associativity_ExpectedAssociative_1_3)
{
    std::vector<std::vector<int>> A = {
        {1, 2, 3},
        {4, 5, 6}
    };

    std::vector<std::vector<int>> B = {
        {10, 0},
        {0, 10},
        {9, 9},
    };

    std::vector<std::vector<int>> B1 = {
        {10, 0},
        {0, 0},
        {9, 0}
    };

    std::vector<std::vector<int>> B2 = {
        {0, 0},
        {0, 10},
        {0, 9}
    };

    std::vector<std::vector<int>> C1(2, std::vector<int>(2, 0));
    std::vector<std::vector<int>> C2(2, std::vector<int>(2, 0));
    std::vector<std::vector<int>> CASS(2, std::vector<int>(2, 0));

    multiplyMatrices(A, B, CASS, 2, 3, 2);
    multiplyMatrices(A, B1, C1, 2, 3, 2);
    multiplyMatrices(A, B2, C2, 2, 3, 2);

    std::vector<std::vector<int>> CRECONSTRUCTED (2, std::vector<int>(2,0));
    for (std::size_t i = 0; i < 2; ++i)
    {
        for (std::size_t j = 0; j < 2; ++j)
        {
            CRECONSTRUCTED[i][j] = C1[i][j] + C2[i][j];
        }
    }

    ASSERT_EQ(CASS, CRECONSTRUCTED) << "Matrix-Matrix product is expected to be associative";
}

/**
 * @brief Tests the behaviour of a not permitted matrix multiplication based on the dimensions of the matrices
 * @note Expected behaviour is unknown and could be implementation/architecture dependent. ASSERT_DEATH_IF_SUPPORTED is used.
 * Testing suggests that no control interrupts the flow if enough memory is allocated to C even though dimensions may be incorrect.
 *
 * @note Causes Error 7 -> Result matrix contains a number between 11 and 20
 * @note Causes Error 14 -> The result matrix has an even number of rows
 * @note Causes Error 18 -> Matrix A is a square matrix
 * @note Causes Error 20 -> Number of columns in matrix A is odd
 * 
 */
TEST(AlgebraicMultiplyMatrices, NotPermittedMultiplication_ExpectedUnknownBehavior_1_4)
{
    std::vector<std::vector<int>> A = {
        {15}
    };

    std::vector<std::vector<int>> B = {
        {1, 1, 1},
        {22, 23, 24}
    };

    std::vector<std::vector<int>> C (50, std::vector<int>(50, 0));

    ASSERT_DEATH_IF_SUPPORTED(multiplyMatrices(A, B, C, 1, 1, 3), "");
};



/**
 * @brief Entry point for test execution.
 */
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
