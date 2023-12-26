#include "FuncTable.h"

#define NUMRECORDS 8

static FuncTable FunctionTable[NUMRECORDS] = {
    {"100000", "add"},
    {"NULL", "addi"},
    {"000010", "mul"},
    {"NULL", "beq"},
    {"NULL", "lui"},
    {"NULL", "lw"},
    {"NULL", "sw"},
    {"100010", "sub"} 
};

const FuncTable* FindFunc(const char* const func)
{
    for (int i = 0; i < NUMRECORDS; i++)
    {
        if (strcmp(func, FunctionTable[i].mnemonic) == 0)
        {
            return &FunctionTable[i];
        }
    }
    return NULL;
}