# Lab_03_01_01 tests
## Input data
- Number of rows in a matrix;
- Number of columns in a matrix;
- Elements of a matrix, line by line.
## Output data
- A matrix with shifted elements whose sum of digits is greater than `10`.
## Positive tests
- There is one element in the matrix, and it's sum of digits is greater than `10`;
- One row, `5` columns, there are elements with sum of digits greater than `10`;
- `4` rows, `4` columns, all elements are equal;
- `10` rows, `10` columns;
- All elements of matrix have sum of digits greater than `10`.
## Negative tests
- Invalid number of rows;
- Invalid number of columns;
- Wrong matrix element;
- There aren't elements with sum of digits greater than `10`
- File is empty.