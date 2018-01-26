# Ceeduko

### A sudoku solver written in C++

- [About](#about)
- [Status](#status)
- [Building](#building)
- [Future](#future)
- [License](#license)

About
------
A simple sudoku solver which uses a recursive backtracking algorithm to find the first possible solution. If more than one solution is possible it finds the first. In the future we hope to add other solvers, and show give solutions for any board layout. Currently only supports square matrices of 4X4 and 9X9.

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

Future
------
To do:
- Other solvers
- Many solutions
- Python API
- and more

License
--------
The Solver source code and related files and documentation are distributed under a permissive free software license (BSD-style).  See the [LICENSE](https://raw.githubusercontent.com/thomasms/Solver/master/LICENSE) file for more details.

