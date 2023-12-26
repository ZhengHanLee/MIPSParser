#include "ASMParser.h"
#include "OpTable.h"
//#include "Reg.h"
#include "Reg.h"
#include "FuncTable.h"


/***  Add include directives for here as needed.  ***/

#include <inttypes.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

/**  Breaks up given the MIPS32 assembly instruction and creates a proper 
* ParseResult object storing information about that instruction. 
* 
* Pre:  pASM points to an array holding the representation of a 
* syntactically valid assembly instruction, whose mnemonic is 
* one of the following: 
* 
* add addi mul beq lui lw sw sub 
* 
* The instruction will be formatted as follows: 
* 
* <mnemonic><ws><operand1>,<ws><operand2>,<ws>... 
* 
* where <ws> is an arbitrary mixture of space and tab characters. 
* 
* Returns: 
* A pointer to a proper ParseResult object whose fields have been 
* correctly initialized to correspond to the target of pASM. 
*/ 
ParseResult* parseASM(const char* const pASM) {
	
   
   /***  Implementation here is up to you!  ***/
   char* curr = (char*) pASM;
   char* word;
   ParseResult* result = (ParseResult*) calloc(1000, sizeof(ParseResult));

   result->ASMInstruction = (char*) calloc(1000, sizeof(char*));
   strcpy(result->ASMInstruction, pASM);

   word = strtok(curr, " \t()");
   //char* trimmed = strtok(curr, " "); //obtained trimmed string
   result->Mnemonic = (char*) calloc(1000, sizeof(char*));
   strcpy(result->Mnemonic, word);

   // R-format case   
   if (strcmp(result->Mnemonic, "add") == 0 
      || strcmp(result->Mnemonic, "mul") == 0 
      || strcmp(result->Mnemonic, "sub") == 0 )
   {
      //Funct
      result->Funct = (char*) calloc(1000, sizeof(char*));
      strcpy(result->Funct, FindFunc(result->Mnemonic)->funcBits);
      //Opcode
      result->Opcode = (char*) calloc(1000, sizeof(char*));
      strcpy(result->Opcode, Find(result->Mnemonic)->code);

      word = strtok(NULL, " \t()");
      //rdName
      result->rdName = (char*) calloc(1000, sizeof(char*));
      strcpy(result->rdName, word);
      //RD
      result->RD = (char*) calloc(1000, sizeof(char*));
      strcpy(result->RD, FindReg(result->rdName)->bitNum);
      //rd
      result->rd = FindReg(result->rdName)->intNum;
      //rsName
      word = strtok(NULL, " \t()");
      result->rsName = (char*) calloc(1000, sizeof(char*));
      strcpy(result->rsName, word);
      //RS
      result->RS = (char*) calloc(1000, sizeof(char*));
      strcpy(result->RS, FindReg(result->rsName)->bitNum);
      //rs
      result->rs = FindReg(result->rsName)->intNum;
      //rtName
      word = strtok(NULL, " \t()");
      result->rtName = (char*) calloc(1000, sizeof(char*));
      strcpy(result->rtName, word);
      //RT
      result->RT = (char*) calloc(1000, sizeof(char*));
      strcpy(result->RT, FindReg(result->rtName)->bitNum);
      //rt
      result->rt = FindReg(result->rtName)->intNum;
      //Immediates
      result->Imm = 0;
      result->IMM = NULL;
   }
   //I-format (with reg1, reg2, immediate) case
   else if (strcmp(result->Mnemonic, "addi") == 0
      || strcmp(result->Mnemonic, "beq") == 0)
   {
      result->Opcode = (char*) calloc(1000, sizeof(char*));
      strcpy(result->Opcode, Find(result->Mnemonic)->code);
      word = strtok(NULL, " ,\t()");

      result->Funct = NULL;
      
      //RD
      result->rdName = NULL;
      result->RD = NULL;
      result->rd = 255;
      //RT
      result->rtName = (char*) calloc(1000, sizeof(char*));
      strcpy(result->rtName, word);
      result->RT = (char*) calloc(1000, sizeof(char*));
      strcpy(result->RT, FindReg(result->rtName)->bitNum);
      result->rt = FindReg(result->rtName)->intNum;
      //RS
      word = strtok(NULL, " ,\t()");
      result->rsName = (char*) calloc(1000, sizeof(char*));
      strcpy(result->rsName, word);
      result->RS = (char*) calloc(1000, sizeof(char*));
      strcpy(result->RS, FindReg(result->rsName)->bitNum);
      result->rs = FindReg(result->rsName)->intNum;
      //Imm
      word = strtok(NULL, " ,\t()");
      result->Imm = atoi(word);
      //IMM
      result->IMM = (char*) calloc(16, sizeof(char*));
      strcpy(result->IMM, decimalToBinary(atoi(word)));
   }
   //I-format (with reg1, immediate) case
   else if(strcmp(result->Mnemonic, "lui") == 0)
   {
      result->rtName = (char*) calloc(10, sizeof(char*));
      word = strtok(NULL, " ,\t()");
      strcpy(result->rtName, word);
      result->RD = NULL;
      result->rdName = NULL;
      result->rsName = NULL;
		result->Funct = NULL;
      result->rd = 255;
		result->rs = 0;
		result->rt = FindReg(result->rtName)->intNum;
      result->IMM = (char*) calloc(10, sizeof(char*));
      word = strtok(NULL, " ,\t()");
      result->Imm = atoi(word);
      result->IMM = (char*) calloc(16, sizeof(char*));
		result->Opcode = (char*) calloc(10, sizeof(char*));
		result->RT = (char*) calloc(10, sizeof(char*));
		result->RS = (char*) calloc(10, sizeof(char*));
      strcpy(result->RS,"00000");
		strcpy(result->Opcode, Find(result->Mnemonic)->code);
		strcpy(result->RT, FindReg(result->rtName)->bitNum);
		strcpy(result->IMM, decimalToBinary(atoi(word)));
   }
   //I-format (with reg1, offset(reg2)) case
   else {
      result->rdName = NULL;
      result->rsName = (char*) calloc(10, sizeof(char*));
		result->rtName = (char*) calloc(10, sizeof(char*));
      word = strtok(NULL, " ,\t()");
      strcpy(result->rtName, word);
      word = strtok(NULL, " ,\t()");
      result->IMM = (char*) calloc(16, sizeof(char*));
      result->Imm = atoi(word);
      strcpy(result->IMM, decimalToBinary(atoi(word)));
      word = strtok(NULL, " ,\t()");
      strcpy(result->rsName, word);
      result->rd = 255;
		result->rs = FindReg(result->rsName)->intNum;
		result->rt = FindReg(result->rtName)->intNum;
      result->Funct = NULL;
		result->Opcode = (char*) calloc(10, sizeof(char*));
		result->RS = (char*) calloc(10, sizeof(char*));
		result->RT = (char*) calloc(10, sizeof(char*));
      strcpy(result->Opcode, Find(result->Mnemonic)->code);
		strcpy(result->RS, FindReg(result->rsName)->bitNum);
		strcpy(result->RT, FindReg(result->rtName)->bitNum);
   }
   
   return result;
}
