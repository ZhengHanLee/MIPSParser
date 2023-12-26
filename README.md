# MIPSParser
The MIPS32 Assembly Parser is a C library that provides a function to parse MIPS32 assembly instructions. It is designed to break down the given MIPS32 assembly instruction and create a ParseResult object storing information about that instruction.

    ASMParser.h: Header file containing function prototypes and structure definitions.
    OpTable.h: Header file with information about MIPS32 instructions and their opcodes.
    Reg.h: Header file with information about MIPS32 registers.
  
# Functionality
The parser supports the following MIPS32 assembly instructions:

    add
    addi
    mul
    beq
    lui
    lw
    sw
    sub

The parsed information is stored in a ParseResult object, which includes fields such as:

    ASMInstruction: Original assembly instruction.
    Mnemonic: Instruction mnemonic (e.g., "add", "addi").
    Funct: Function code for R-format instructions.
    Opcode: Opcode for the instruction.
    Register information:
        rdName, rd: Destination register.
        rsName, rs: Source register.
        rtName, rt: Target register.
    Imm: Immediate value.
    IMM: Binary representation of the immediate value.
