# Function-Level Profiling Instrumentor

## Compiler Design Mini Project

### Overview

The Function-Level Profiling Instrumentor is a compiler-based tool that analyzes C source code, constructs an Abstract Syntax Tree (AST), builds a Symbol Table, and automatically inserts profiling hooks into functions. The generated instrumented code can be used to measure function execution statistics such as call counts and execution time.

This project demonstrates key concepts of Compiler Design including lexical analysis, parsing, syntax tree construction, symbol table management, source-to-source transformation, and runtime profiling.

---

## Features

* Lexical Analysis using Flex
* Syntax Analysis using Bison
* Abstract Syntax Tree (AST) Construction
* Symbol Table Generation
* Function-Level Code Instrumentation
* Runtime Profiling Support
* Profiling Report Generation
* Support for Recursive Functions
* Support for Control Flow Statements

  * if-else
  * while
  * for

---

## Project Structure

```
FunctionProfiler/
│
├── lexer.l
├── parser.y
├── Makefile
│
├── ast/
│   ├── ast.h
│   └── ast.cpp
│
├── symboltable/
│   ├── symboltable.h
│   └── symboltable.cpp
│
├── instrumentor/
│   ├── instrumentor.h
│   └── instrumentor.cpp
│
├── profiler/
│   ├── profiler.h
│   └── profiler.c
│
├── report/
│   ├── report.h
│   └── report.cpp
│
└── tests/
    ├── sample1.c
    ├── sample2.c
    └── recursive.c
```

---

## Requirements

### macOS

Install dependencies using Homebrew:

```bash
brew install flex bison
```

### Linux

```bash
sudo apt install flex bison g++
```

---

## Building the Project

Compile the entire project:

```bash
make
```

Clean generated files:

```bash
make clean
```

Rebuild:

```bash
make rebuild
```

---

## Running the Project

### Sample Test 1

```bash
./profiler_compiler < tests/sample1.c
```

### Sample Test 2

```bash
./profiler_compiler < tests/sample2.c
```

### Recursive Function Test

```bash
./profiler_compiler < tests/recursive.c
```

---

## Sample Input

```c
int add(int a, int b)
{
    int result = a + b;
    return result;
}

int main()
{
    int x = add(10, 20);
    return x;
}
```

---

## Sample AST Output

```
===== AST =====

Function: add Return Type: int
    Parameter: int a
    Parameter: int b
    Statement: int result = a + b;
    Statement: return result;

Function: main Return Type: int
    Statement: int x = add(...);
    Statement: return x;

===============
```

---

## Compiler Design Concepts Used

### Lexical Analysis

The lexer identifies tokens such as:

* Keywords
* Identifiers
* Constants
* Operators
* Delimiters

### Syntax Analysis

The parser validates program structure using context-free grammar rules.

### Abstract Syntax Tree (AST)

The AST represents the hierarchical structure of the source program.

### Symbol Table

Stores information about:

* Functions
* Variables
* Data Types
* Parameters

### Code Instrumentation

Profiling hooks are inserted automatically at function entry and exit points.

### Runtime Profiling

Execution statistics are collected during program execution and summarized in a profiling report.

---

## Supported Language Constructs

* Function Definitions
* Function Parameters
* Variable Declarations
* Assignments
* Arithmetic Expressions
* Comparison Expressions
* Function Calls
* Return Statements
* if-else Statements
* while Loops
* for Loops
* Recursive Function Calls

---

## Future Enhancements

* Full C Language Support
* Nested Scope Symbol Tables
* Optimization Passes
* CFG (Control Flow Graph) Generation
* Enhanced Profiling Metrics
* Graphical Profiling Reports

---

## Author

Aditya Sahay

3rd year project
B.Tech Computer Science Engineering
RV College Of Engineering

Compiler Design Project
