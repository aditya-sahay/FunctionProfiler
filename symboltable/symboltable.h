#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

/* ==========================
   Symbol Entry
   ========================== */

class SymbolEntry
{
public:

    string name;
    string type;

    string scope;

    int parameterCount;

    vector<string> parameterTypes;

    SymbolEntry()
    {
        parameterCount = 0;
    }

    SymbolEntry(
        const string& n,
        const string& t,
        const string& s
    )
    {
        name = n;
        type = t;
        scope = s;
        parameterCount = 0;
    }

    void print() const
    {
        cout << "Name: " << name
             << " | Type: " << type
             << " | Scope: " << scope
             << " | Parameters: "
             << parameterCount
             << endl;
    }
};

/* ==========================
   Symbol Table
   ========================== */

class SymbolTable
{
private:

    unordered_map<string, SymbolEntry> table;

public:

    SymbolTable() {}

    bool insert(
        const string& name,
        const string& type,
        const string& scope
    )
    {
        if(table.find(name) != table.end())
        {
            return false;
        }

        table[name] =
            SymbolEntry(name, type, scope);

        return true;
    }

    bool exists(
        const string& name
    ) const
    {
        return table.find(name)
               != table.end();
    }

    SymbolEntry* lookup(
        const string& name
    )
    {
        auto it = table.find(name);

        if(it == table.end())
            return nullptr;

        return &(it->second);
    }

    void addParameter(
        const string& functionName,
        const string& parameterType
    )
    {
        auto it = table.find(functionName);

        if(it == table.end())
            return;

        it->second.parameterTypes.push_back(
            parameterType
        );

        it->second.parameterCount++;
    }

    void print()
    {
        cout << "\n===== SYMBOL TABLE =====\n";

        for(auto& entry : table)
        {
            entry.second.print();
        }

        cout << "========================\n";
    }
};

extern SymbolTable globalSymbolTable;

#endif