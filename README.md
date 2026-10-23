
# C++ Modules

My solutions to the C++ modules of the 42 curriculum: a step-by-step introduction to object-oriented programming in C++, from the first class to the STL.

Each module focuses on one group of concepts and builds on the previous ones.

## Modules

| Module | Topics | Status |
|---|---|---|
| [CPP00](CPP00) | Classes, member functions and I/O streams | Done |
| [CPP01](CPP01) | Memory allocation, pointers and references | Done |
| [CPP02](CPP02) | Operator overloading and Orthodox Canonical Form | Done |
| [CPP03](CPP03) | Inheritance | Done |
| [CPP04](CPP04) | Polymorphism, abstract classes and interfaces | Done |
| [CPP05](CPP05) | Exceptions and error handling | Done |
| [CPP06](CPP06) | Type casting | Done |
| [CPP07](CPP07) | Templates | Done |
| [CPP08](CPP08) | Containers, iterators and algorithms | In progress |
| CPP09 | STL in practice | Upcoming |

## What I learned

- **CPP00**: writing a first class, with private attributes, public member functions, constructors and destructors.
- **CPP01**: the difference between stack and heap, `new` and `delete`, and when to use a reference instead of a pointer.
- **CPP02**: giving a class its own operators (`+`, `<`, `<<`...) and the four functions every class needs: default constructor, copy constructor, copy assignment operator and destructor.
- **CPP03**: reusing code through inheritance, and the order in which constructors and destructors run.
- **CPP04**: `virtual` functions, deep copies of objects that own memory, abstract classes and interfaces.
- **CPP05**: reporting errors with `throw`, `try` and `catch`, and writing custom exception classes that inherit from `std::exception`.
- **CPP06**: the four C++ casts (`static_cast`, `dynamic_cast`, `reinterpret_cast`, `const_cast`), converting between scalar types, and identifying the real type of an object at runtime.
- **CPP07**: function templates and class templates, to write code once and use it with any type.
- **CPP08**: the standard containers (`vector`, `list`, `stack`...), iterators to walk through them, and the ready-made functions of `<algorithm>`.
- **CPP09**: choosing the right container for each problem, applied to three programs: a price lookup by date, a Reverse Polish Notation calculator and a merge-insertion sort.

## Structure

```
CPP00/
├── ex00/
├── ex01/
└── ...
CPP01/
└── ...
```

Every exercise lives in its own folder, with its source files and a `Makefile`.

## Usage

```bash
git clone <repository-url>
cd <repository-name>/CPP05/ex00
make
./<program-name>
```

All exercises compile with `c++` and the flags `-Wall -Wextra -Werror`.

Useful Makefile rules:

| Rule | Action |
|---|---|
| `make` | builds the program |
| `make clean` | removes object files |
| `make fclean` | removes object files and the program |
| `make re` | rebuilds from scratch |

## Notes

These exercises are part of my learning process at 42. If you are a 42 student, use this repository as a reference only: the point of the modules is to work through them yourself.