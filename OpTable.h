//Static lookup table for operations

#ifndef OPTABLE_H
#define OPTABLE_H
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

//Define struct
// struct OpTable
// {
//     /* data */
//     char* code;
//     char* funcBits;
//     char* mnemonic;
// };

struct _OpTable
 {
     /* data */
     char* code;
     char* mnemonic;
 };

typedef struct _OpTable OpTable;

const OpTable* Find(const char* const op);

#endif

