//Static lookup table for registers

#ifndef FUNCTABLE_H
#define FUNCTABLE_H
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

//Define function struct
struct _Func 
{
    char* funcBits;
    char* mnemonic;
};

typedef struct _Func FuncTable;

const FuncTable* FindFunc(const char* const func);

#endif