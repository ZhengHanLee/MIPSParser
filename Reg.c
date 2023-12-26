#include "Reg.h"

#define NUMRECORDS 8

static Reg RegisterTable[NUMRECORDS] = 
{
    {8, "01000", "$t0"},
    {9, "01001", "$t1"},
    {10, "01010", "$t2"},
    {11, "01011", "$t3"},
    {16, "10000", "$s0"},
    {17, "10001", "$s1"},
    {18, "10010", "$s2"},
    {19, "10011", "$s3"}
};

const Reg* FindReg(const char* const reg)
{
    for (int i = 0; i < NUMRECORDS; i++)
    {
        if (strcmp(reg, RegisterTable[i].name) == 0)
        {
            return &RegisterTable[i];
        }
    }
    return NULL;
}

char* decimalToBinary(int num)
{
    char* result = calloc(16, sizeof(char*));
    int place;
    int bit;

    for(place = 15; place >= 0; place--) {
        bit = num >> place;

        if(bit & 1) {
            result[15 - place] = '1';
        }
        else {
            result[15 - place] = '0';
        }
    }
    return result;
}