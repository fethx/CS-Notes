
## Table of Contents
- [1. Linux tools](#linux)
- [2. C++](#c++)
    - [Courses](#courses)
    - [Books](#books)
    - [STL](#stl)

## 1. Linux tools <a id="linux"></a>
[MIT：The Missing Semester of Your CS Education](https://missing.csail.mit.edu/)

>Lectures:
- [Course overview + the shell](https://missing.csail.mit.edu/2020/course-shell/)
- [Shell Tools and Scripting](https://missing.csail.mit.edu/2020/shell-tools/)
- [Editors (Vim)](https://missing.csail.mit.edu/2020/editors)
- [Data Wrangling](https://missing.csail.mit.edu/2020/data-wrangling)
- [Command-line Environment](https://missing.csail.mit.edu/2020/command-line)
- [Version Control (Git)](https://missing.csail.mit.edu/2020/version-control)
- [Debugging and Profiling](https://missing.csail.mit.edu/2020/debugging-profiling)
- [Metaprogramming](https://missing.csail.mit.edu/2020/metaprogramming)
- [Security and Cryptography](https://missing.csail.mit.edu/2020/security)
- [Potpourri](https://missing.csail.mit.edu/2020/potpourri)
- [Q&amp;A](https://missing.csail.mit.edu/2020/qa)


## 2. C++ <a id="c++"></a>
### Courses <a id="courses"></a>
Stanford University [CS 106L: Standard C++ Programming](http://web.stanford.edu/class/cs106l/index.html)

### Books <a id="books"></a>
[The Definitive C++ Book Guide and List](https://stackoverflow.com/questions/388242/the-definitive-c-book-guide-and-list/388282#388282)

### STL <a id="stl"></a>

#### STL container 

Container | Underlying data structure | Time complexity | Other
---|---|---|---
[deque](https://en.cppreference.com/w/cpp/container/deque) | The elements of a deque are not stored contiguously: typical implementations use a sequence of individually allocated fixed-size **arrays**, with additional bookkeeping. | 1. Random access - constant O(1) <br /> 2. Insertion or removal of elements at the end or beginning - constant O(1) <br /> 3. Insertion or removal of elements - linear O(n) | | | The storage of a deque is automatically **expanded** and **contracted** as needed.
