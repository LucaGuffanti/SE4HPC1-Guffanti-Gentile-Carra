/**
 * @file structural.cpp
 * @brief Test cases that verify the consistency of structural (i.e. software/implementation related) properties for the provided matrix
 * multiplication function.
 */

#include "matrix_multiplication.h"
#include <iostream>
#include <vector>
#include <gtest/gtest.h>


/**
 * @brief Entry point for test execution.
 */
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
