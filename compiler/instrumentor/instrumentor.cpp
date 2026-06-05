#include "instrumentor.h"

/*
=====================================
Constructor
=====================================
*/

Instrumentor::Instrumentor(
    const string& outputFilename
)
{
    outputFile.open(outputFilename);

    if(!outputFile.is_open())
    {
        cerr << "Error opening output file: "
             << outputFilename
             << endl;
    }
}

/*
=====================================
Destructor
=====================================
*/

Instrumentor::~Instrumentor()
{
    if(outputFile.is_open())
    {
        outputFile.close();
    }
}

/*
=====================================
Write One Line
=====================================
*/

void Instrumentor::writeLine(
    const string& line
)
{
    if(outputFile.is_open())
    {
        outputFile << line << endl;
    }
}

/*
=====================================
Insert profiler_start()
=====================================
*/

void Instrumentor::insertProfilerStart(
    const string& functionName
)
{
    writeLine(
        "    profiler_start(\"" +
        functionName +
        "\");"
    );
}

/*
=====================================
Insert profiler_end()
=====================================
*/

void Instrumentor::insertProfilerEnd(
    const string& functionName
)
{
    writeLine(
        "    profiler_end(\"" +
        functionName +
        "\");"
    );
}

/*
=====================================
Instrument One Function
=====================================
*/

void Instrumentor::instrumentFunction(
    FunctionNode* function
)
{
    if(function == nullptr)
        return;

    /*
        Function Header
    */

   string signature =
    function->returnType +
    " " +
    function->functionName +
    "(";

for(size_t i = 0;
    i < function->parameters.size();
    i++)
{
    ParameterNode* p =
        function->parameters[i];

    signature +=
        p->type +
        " " +
        p->name;

    if(i != function->parameters.size() - 1)
    {
        signature += ", ";
    }
}

signature += ")";

writeLine(signature);

    writeLine("{");

    /*
        Entry Hook
    */

    insertProfilerStart(
    function->functionName
);

bool hasReturn = false;

for(auto stmt : function->body)
{
    if(stmt->text.find("return") == 0)
    {
        hasReturn = true;

        insertProfilerEnd(
            function->functionName
        );
    }

    writeLine(
        "    " +
        stmt->text
    );
}

if(function->functionName == "main")
{
    writeLine(
        "    profiler_print_report();"
    );
}

if(!hasReturn)
{
    insertProfilerEnd(
        function->functionName
    );
}

writeLine("}");
writeLine("");
}
/*
=====================================
Instrument Entire Program
=====================================
*/

void Instrumentor::instrumentProgram(
    ProgramNode* root
)
{
    if(root == nullptr)
        return;

    /*
        Required Include
    */

    writeLine("#include <stdio.h>");
writeLine("#include \"profiler.h\"");
writeLine("");

    /*
        Generate All Functions
    */

    for(auto function : root->functions)
    {
        instrumentFunction(
            function
        );
    }
}