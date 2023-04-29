# Lab_04_03_01 tests
## Input data
- Line.
## Output data
- New line with changed words from the given line. 
- Program leaves only the first occurrences of each letter in the word.
## Positive tests
- `5` different words with unique letters;
- `2` different words with unique letters, separated by different characters;
- `4` different words with length `1`, separated by different characters;
- There are duplicated words in the line, there are duplicated characters in the words;
- There are more duplicated words in the line, there are duplicated characters in the words;
- There is a duplicated word in the line, there are duplicated characters in the words.
## Negative tests
- File is empty;
- There are only separators in the line;
- Word length is bigger than 16;
- There is only one word in the line;
- Length of the line is bigger than `256`.