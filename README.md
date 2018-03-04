# Ceeduko

### A sudoku solver written in C++

[![Build Status](https://travis-ci.org/thomasms/ceeduko.svg?branch=master)](https://travis-ci.org/thomasms/ceeduko)
[![codecov](https://codecov.io/gh/thomasms/ceeduko/branch/master/graph/badge.svg)](https://codecov.io/gh/thomasms/ceeduko)

- [About](#about)
- [Status](#status)
- [Building](#building)
- [Run](#run)
- [Future](#future)
- [License](#license)

About
------
A simple sudoku solver which uses a recursive backtracking algorithm to find the first possible solution. If more than one solution is possible it finds the first. In the future we hope to add other solvers, and determine solutions for any board layout. Currently only supports square matrices of any size, but be warned the current solver is very slow above the traditional 9x9 board.
Some sample boards exist of sizes: 4x4, 9x9, 16x16 and 100x100. The last will run very slow!

Status
------
Still lot's to do. Watch this space.

Building
------
Uses cmake to compile.
```bash
mkdir build
cd build
cmake ..    #point to top level CMakeLists.txt
make -j${NCPUS}
```
Run
------
Currently, it will only build a command line program 'ceeduko' and the unit tests 'ceedukotests'.
To run the command line program, it simply takes one argument, the filename of the board, as below:
```bash
./build/bin/ceeduko boards/9x9_partial.board
```
Giving the following output.
```bash
Solution found!
9 9
5 7 6 2 3 8 1 4 9
2 3 9 4 1 6 5 7 8
4 1 8 5 9 7 2 3 6
1 6 2 9 4 5 7 8 3
7 4 3 1 8 2 9 6 5
8 9 5 7 6 3 4 1 2
6 5 4 3 2 1 8 9 7
3 2 1 8 7 9 6 5 4
9 8 7 6 5 4 3 2 1
```
This will then produce an output file, with the same name as the input, but with '.solved' appened.
There are some sample boards in sub directory, boards, to use an example. The file format is:

<number of rows> <number of columns>
<board>

The numbers in the board are whitespace separated, and if a value is unknown an asterisk is used '*'.

Future
------
To do:
- Improve serialization, allow for larger boards - Can support square boards larger than 9x9 but it very slow for boards above this size.
- Performance improvements needed
- Other solvers
- Many solutions
- Python API
- and more

License
--------
The Solver source code and related files and documentation are distributed under a permissive free software license (BSD-style).  See the [LICENSE](https://raw.githubusercontent.com/thomasms/Solver/master/LICENSE) file for more details.

