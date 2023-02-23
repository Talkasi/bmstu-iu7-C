# Lab_01_07_01 tests
## Input data
- double x, eps;
## Output data
- double absolute_error, relative_error;
## Positive tests
- `x` is zero, `eps` is `0.1`;
- `x` is `0.1`, `eps` is `0.01`;
- `x` is `0.5`, `eps` is `0.9375`.
## Negative tests
- `|x|` is bigger than `1` or equal `1`;
- `eps` is a wrong value;
- One of the parameters is not a number.
