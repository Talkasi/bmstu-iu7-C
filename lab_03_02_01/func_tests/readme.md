# Lab_03_01_01 tests
## Input data
- Number of rows in a matrix;
- Number of columns in a matrix;
- Elements of a matrix, line by line.
## Output data
- Matrix with deleted row and column where was found number with minimal sum of digits.
## Positive tests
- Two rows, two columns;
- All elements of matrix are the same;
- There are two elements with minimal sum of digits in different rows and columns;
- There are 10 columns, 10 rows;
- Element with minimal sum of digits is on the `[0][0]` position;
- Element with minimal sum of digits is on the `[n_rows - 1][n_columns - 1]` position.
## Negative tests
- Invalid number of columns;
- Invalid number of rows;
- Wrong matrix element;
- One row, several columns;
- One column, several rows;
- File is empty.