# Lab_05_04_02 tests
## Usage
- `program st SRC_FILE DST_FILE`
- `program ft FILE SUBSTR`
- `program at FILE`
## Positive tests
- Sort products without equal price;
- Sort products with equal price;
- Substring testing with several letters;
- Substring testing with one letter;
- Adding in the beginning of the file testing;
- Adding in the middle of the file testing.
## Negative tests
- No parameters;
- Wrong parameters;
- Input file is empty, `st` key;
- Input file is empty, `at` key;
- Input file is empty, `ft` key;
- Wrong reading-file name, `st` key;
- Wrong reading-file name, `at` key;
- Wrong reading-file name, `ft` key;
- All product names do not end with a substring, `ft` key;
- Wrong length of the product name, `at` key;
- Wrong length of the product manufacture, `at` key;
- Wrong product price, `at` key;
- Wrong number of products, `at` key.
