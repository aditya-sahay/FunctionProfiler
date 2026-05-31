#ifndef AST_H
#define AST_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

/* ==========================
   Base AST Node
   ========================== */

class ASTNode
{
public:
    virtual ~ASTNode() {}
    virtual void print(int indent = 0) = 0;
};

/* ==========================
   Parameter Node
   ========================== */

class ParameterNode : public ASTNode
{
public:
    string type;
    string name;

    ParameterNode(const string& t, const string& n)
        : type(t), name(n) {}

    void print(int indent = 0) override
    {
        for(int i=0;i<indent;i++) cout << " ";
        cout << "Parameter: "
             << type
             << " "
             << name
             << endl;
    }
};

/* ==========================
   Statement Node
   ========================== */

class StatementNode : public ASTNode
{
public:
    string text;

    StatementNode(const string& t)
        : text(t) {}

    void print(int indent = 0) override
    {
        for(int i=0;i<indent;i++) cout << " ";
        cout << "Statement: "
             << text
             << endl;
    }
};

/* ==========================
   Function Node
   ========================== */

class FunctionNode : public ASTNode
{
public:

    string returnType;
    string functionName;

    string sourceCode;

    vector<ParameterNode*> parameters;

    vector<StatementNode*> body;

    FunctionNode(
    const string& retType,
    const string& funcName
)
    : returnType(retType),
      functionName(funcName),
      sourceCode("")
{
}

    void addParameter(ParameterNode* param)
    {
        parameters.push_back(param);
    }

    void addStatement(StatementNode* stmt)
    {
        body.push_back(stmt);
    }

    void print(int indent = 0) override
    {
        for(int i=0;i<indent;i++) cout << " ";

        cout << "Function: "
             << functionName
             << " Return Type: "
             << returnType
             << endl;

        for(auto p : parameters)
            p->print(indent + 4);

        for(auto s : body)
            s->print(indent + 4);
    }

    ~FunctionNode()
    {
        for(auto p : parameters)
            delete p;

        for(auto s : body)
            delete s;
    }
};

/* ==========================
   Program Node
   ========================== */

class ProgramNode : public ASTNode
{
public:

    vector<FunctionNode*> functions;

    void addFunction(FunctionNode* func)
    {
        functions.push_back(func);
    }

    FunctionNode* getLastFunction()
    {
        if(functions.empty())
            return nullptr;

        return functions.back();
    }

    void print(int indent = 0) override
    {
        cout << "\n===== AST =====\n";

        for(auto func : functions)
            func->print(indent);

        cout << "===============\n";
    }

    ~ProgramNode()
    {
        for(auto func : functions)
            delete func;
    }
};

/* ==========================
   Global AST Root
   ========================== */

extern ProgramNode* root;

#endif