#include "ast.h"

/*
    Global AST Root

    The parser inserts all discovered functions
    into this tree.
*/

ProgramNode* root = nullptr;