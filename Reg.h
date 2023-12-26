//Static lookup table for registers

#ifndef REG_H
#define REG_H
#include <inttypes.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

//Define register struct
struct _Reg
{
    uint8_t intNum; //Integer representation
    char* bitNum; //bit representation
    char* name; //$t0
};

typedef struct _Reg Reg;

const Reg* FindReg(const char* const reg);

char* decimalToBinary(int num);

#endif