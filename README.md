# Function-Level Profiling Instrumentor

## Compiler Design Mini Project

### Overview

The Function-Level Profiling Instrumentor is a compiler-based tool that analyzes C source code, constructs an Abstract Syntax Tree (AST), builds a Symbol Table, and automatically inserts profiling hooks into functions. The generated instrumented code can be used to measure function execution statistics such as function calls and execution time.

The project demonstrates core Compiler Design concepts including Lexical Analysis, Parsing, AST Construction, Symbol Table Management, Source-to-Source Transformation, Code Instrumentation, Runtime Profiling, and a modern React-based visualization interface.

---

# Features

### Compiler Components

* Lexical Analysis using Flex
* Syntax Analysis using Bison
* Abstract Syntax Tree (AST) Construction
* Symbol Table Generation
* Function-Level Instrumentation
* Runtime Profiling Support
* Profiling Report Generation

### Language Support

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

### Frontend Features

* React-based User Interface
* Drag-and-Drop / File Upload Support
* Project Information Dashboard
* Live Compiler Output Display
* Backend Integration with Compiler
* Terminal-style Analysis View

---

# Project Architecture

```text
+------------------+
| React Frontend   |
+--------+---------+
         |
         | Upload C File
         v
+------------------+
| Node.js Backend  |
| Express Server   |
+--------+---------+
         |
         | Execute
         v
+------------------+
| Compiler Module  |
| Flex + Bison     |
+--------+---------+
         |
         v
+------------------+
| AST Construction |
+------------------+

+------------------+
| Symbol Table     |
+------------------+

+------------------+
| Instrumentation  |
+------------------+

+------------------+
| Runtime Profiler |
+------------------+

         |
         v

 Profiling Report
```

---

# Project Structure

```text
FunctionProfiler/
│
├── compiler/
│   └── profiler_compiler
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
├── backend/
│   ├── server.js
│   ├── package.json
│   └── uploads/
│
├── frontend/
│   ├── src/
│   ├── public/
│   └── package.json
│
└── tests/
    ├── sample1.c
    ├── sample2.c
    └── recursive.c
```

---

# Requirements

## Windows

### Install

* Flex for Windows
* Bison for Windows
* MinGW-w64 (G++)
* Node.js (LTS Version)

Verify:

```bash
flex --version
bison --version
g++ --version
node -v
npm -v
```

---

## Linux (Ubuntu/Debian)

```bash
sudo apt update

sudo apt install flex bison g++ make nodejs npm
```

Verify:

```bash
flex --version
bison --version
g++ --version
node -v
npm -v
```

---

## macOS

Install Homebrew first if required.

```bash
brew install flex
brew install bison
brew install node
```

Verify:

```bash
flex --version
bison --version
g++ --version
node -v
npm -v
```

---

# Building the Compiler

## Clean

```bash
make clean
```

## Build

```bash
make
```

## Rebuild

```bash
make clean
make
```

Successful build generates:

```text
compiler/profiler_compiler
```

---

# Running the Compiler

## Sample Test 1

```bash
./compiler/profiler_compiler < tests/sample1.c
```

## Sample Test 2

```bash
./compiler/profiler_compiler < tests/sample2.c
```

## Recursive Function Test

```bash
./compiler/profiler_compiler < tests/recursive.c
```

---

# Running the Backend

Move into backend directory:

```bash
cd backend
```

Install dependencies:

```bash
npm install
```

Start server:

```bash
node server.js
```

Expected Output:

```text
Server running on port 5000
```

Backend URL:

```text
http://localhost:5000
```

---

# Running the Frontend

Move into frontend directory:

```bash
cd frontend
```

Install dependencies:

```bash
npm install
```

Start React application:

```bash
npm run dev
```

Expected Output:

```text
Local:
http://localhost:5173
```

Open the URL in a browser.

---

# Using the Application

1. Build the compiler using:

```bash
make
```

2. Start backend:

```bash
node server.js
```

3. Start frontend:

```bash
npm run dev
```

4. Open:

```text
http://localhost:5173
```

5. Upload a C source file.

6. The frontend sends the file to the backend.

7. The backend executes:

```text
compiler/profiler_compiler
```

8. Compiler output is displayed directly in the browser.

---

# Sample AST Output

```text
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

# Compiler Design Concepts Used

## Lexical Analysis

Performed using Flex.

Recognizes:

* Keywords
* Identifiers
* Constants
* Operators
* Delimiters

---

## Syntax Analysis

Performed using Bison.

Validates program structure using Context-Free Grammar (CFG).

---

## Abstract Syntax Tree (AST)

Represents the hierarchical structure of source code.

Stores:

* Functions
* Parameters
* Statements
* Expressions

---

## Symbol Table

Stores information regarding:

* Functions
* Variables
* Data Types
* Parameters

---

## Code Instrumentation

Automatically inserts:

```c
profiler_start();
profiler_end();
```

into generated code.

---

## Runtime Profiling

Collects:

* Function Call Count
* Execution Statistics
* Recursive Function Data

---

# Current Limitations

* Partial C Language Support
* No Pointer Handling
* No Arrays
* No Structs
* No Nested Symbol Tables
* No Semantic Type Checking

---

# Future Enhancements

* Full ANSI C Support
* Semantic Analysis Phase
* Intermediate Code Generation
* Control Flow Graph (CFG)
* Data Flow Analysis
* Optimization Passes
* Interactive Profiling Dashboard
* Profiling Graph Visualizations
* Execution Timeline Charts

---

# Authors

### Aditya Sahay

### Aditya Menia

B.Tech Computer Science and Engineering

RV College of Engineering

Compiler Design Mini Project
