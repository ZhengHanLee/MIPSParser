#include "OpTable.h"

#define NUMRECORDS 8

// static OpTable OperationTable[NUMRECORDS] = {
//     {"000000", "100000", "add"},
//     {"001000", "NULL", "addi"},
//     {"000000", "000010", "mul"},
//     {"000100", "NULL", "beq"},
//     {"001111", "NULL", "lui"},
//     {"100011", "NULL", "lw"},
//     {"101011", "NULL", "sw"},
//     {"000000", "100010", "sub"} 
// };

static OpTable OperationTable[NUMRECORDS] = {
    {"000000", "add"},
    {"001000", "addi"},
    {"000000", "mul"},
    {"000100", "beq"},
    {"001111", "lui"},
    {"100011", "lw"},
    {"101011", "sw"},
    {"000000", "sub"} 
};

const OpTable* Find(const char* const op)
{
    for (int i = 0; i < NUMRECORDS; i++)
    {
        if (strcmp(op, OperationTable[i].mnemonic) == 0)
        {
            return &OperationTable[i];
        }
    }
    return NULL;
}