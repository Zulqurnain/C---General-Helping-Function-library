# C++ General Helping Function Library

A C++ utility library with a wide variety of helper functions for common programming tasks.

## Functions

| Function | Description |
|----------|-------------|
| `chrand(char, char)` | Randomize character within a range |
| `bintodeci(long int)` | Binary to decimal conversion |
| `stf()` | Single precision to float conversion |
| `fts()` | Float to single precision binary |
| `tictac()` | Tic-tac-toe game |
| `paliornot(int)` | Palindrome check |
| `selecsort(int[], int)` | Selection sort |
| `bsearch(int[], int, int)` | Binary search |
| `bubbleSort(T*, int)` | Bubble sort (template) |
| `printAsBits(uint32_t)` | Print integer as bits |
| `passpro(char[])` | Password protection |
| `numOfBytesInFile(FILE*)` | File size in bytes |

## Usage

```cpp
#include "mylib.h"

int main() {
    char c = chrand('a', 'z');  // random lowercase letter
    bool isPalin = paliornot(121);  // true
    return 0;
}
```

## Build

```bash
g++ -std=c++17 your_program.cpp -o output
```

---

**Built by [Zulqurnain Haider](https://zulqurnainj.com/) — Senior Full Stack Engineer**

For full portfolio visit: [https://zulqurnainj.com/](https://zulqurnainj.com/)
