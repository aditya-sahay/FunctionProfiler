#ifndef INSTRUMENTOR_H
#define INSTRUMENTOR_H

#include <iostream>
#include <fstream>
#include <string>

#include "ast.h"

using namespace std;

/*
=====================================
Function-Level Profiling Instrumentor
=====================================

Traverses AST and generates
instrumented source code.
*/

class Instrumentor
{
private:

    ofstream outputFile;

public:

    Instrumentor(
        const string& outputFilename
    );

    ~Instrumentor();

    /*
        Generate entire program
    */
    void instrumentProgram(
        ProgramNode* root
    );

    /*
        Generate one function
    */
    void instrumentFunction(
        FunctionNode* function
    );

    /*
        Write profiler hooks
    */
    void insertProfilerStart(
        const string& functionName
    );

    void insertProfilerEnd(
        const string& functionName
    );

    /*
        Utility
    */
    void writeLine(
        const string& line
    );
};

#endif