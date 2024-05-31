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