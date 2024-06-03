# SE4HPCproject
This is the repository for the SE4HPC project. The project is about the development of a suite of tests for a matrix multiplication function. The tests are developed using the Google Test Library. The tests are developed in a **black box** manner, meaning that the tests are developed without any knowledge of the implementation of the matrix multiplication function.

The function to test has the following signature:
```c++
void multiplyMatrices(const std::vector<std::vector<int>>& A, const std::vector<std::vector<int>>& B, std::vector<std::vector<int>>& C, int rowsA, int colsA, int colsB);
```

## Principles
The tests are developed following the principles of **black box testing**, **reproducibility**, and **orthogonality**. The tests are divided into four categories: 
- `AlgebraicTests`: contains the tests the algebraic properties of the matrix multiplication function.
- `StructuralTests`: contains the tests to verify that the function correctly handles wrong inputs and edge cases.
- `CombinatorialTests`: enumerates a large set of possible inputs and verify that the function returns the correct output.
- `MonkeyTests`: generates random inputs and verify that the function returns the correct output, returning the seed in case of failure. (for reproducibility)

## How to run the tests
To run the the tests, run the following commands:

```bash
mkdir -p build && cd build && rm -r *
cd build
cmake ..
cmake --build .
```

In the `build` directory, you will find the executable `test_multiplication`. This executable contains all the tests. To lists them all, run the following command:

```bash
./test_multiplication --gtest_list_tests
AlgebraicTests.
  ZeroMatrices_ExpectedAllZero_1_1
  IdentityMatrices_ExpectedOriginalMatrix_1_2
  Associativity_ExpectedAssociative_1_3
  NotPermittedMultiplication_ExpectedUnknownBehavior_1_4
  EvenEven_1_5_1
  EvenOdd_1_5_2
  OddEven_1_5_3
  OddOdd_1_5_4
  CorrectRowsAndCols_ExpectCorrect_1_6
  Commutation_ExpectedCommutative_1_7
CombinatorialTests.
  EnumerateAllPossibleCases_1x1
MonkeyTests.
  RandomMatrices
StructuralTests.
  NonCoherentSizes_2_1
  NegativeSizes_2_2
  NumericalRange_2_4
```

Tests are divided into four categories: `AlgebraicTests`, `CombinatorialTests`, `MonkeyTests`, and `StructuralTests`. To run all the tests of a category, run the following command:

```bash
./test_multiplication --gtest_filter=CATEGORY_NAME.*
```

to run a specific test, just specify the full name of the test. For example, to run the test `ZeroMatrices_ExpectedAllZero_1_1`, run the following command:

```bash
./test_multiplication --gtest_filter=AlgebraicTests.ZeroMatrices_ExpectedAllZero_1_1
```
## Identified Errors
As a result, we identified the following errors

| Error ID | Description                                            |
|--------|----------------------------------------------------------|
| 1      | Element-wise multiplication of ones detected!            |
| 2      | Matrix A contains the number 7!                          |
| 3      | Matrix A contains a negative number!                     |
| 4      | Matrix B contains the number 3!                          |
| 5      | Matrix B contains a negative number!                     |
| 6      | Result matrix contains a number bigger than 100!         |
| 7      | Result matrix contains a number between 11 and 20!       |
| 8      | Result matrix contains zero!                             |
| 9      | Result matrix contains the number 99!                    |
| 10     | A row in matrix A contains more than one '1'!            |
| 11     | Every row in matrix B contains at least one '0'!         |
| 12     | The number of rows in A is equal to the number of columns in B! |
| 13     | The first element of matrix A is equal to the first element of matrix B! |
| 14     | The result matrix C has an even number of rows!          |
| 15     | A row in matrix A is filled entirely with 5s!            |
| 16     | Matrix B contains the number 6!                          |
| 17     | Result matrix C contains the number 17!                  |
| 18     | Matrix A is a square matrix!                             |
| 19     | Every row in matrix A contains the number 8!             |
| 20     | Number of columns in matrix A is odd!                    |

More tests cause the same errors(s). For a comprehensive description of the test cases, including the expected behaviour and
the triggered errors, refer to the comments in the source code.

## Acknowledge
Project work carried out by 
- Edoardo Carrà 11015152
- Lorenzo Gentile 11001962
- Luca Guffanti 10720858
