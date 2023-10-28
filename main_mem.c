#include <stdio.h>
#include <stdint.h>
uint16_t PC_START = 0x3000; //unsigned 16 bit integer
uint16_t mem[UINT16_MAX+1] = {0}; // UINT16_MAX = 65535

static inline uint16_t mr(uint16_t address){ return mem[address];}
static inline void mw(uint16_t address, uint16_t val){ mem[address] = val;}


enum regist {R0=0, R1, R2, R3, R4, R5, R6, R7, RPC, RCND, RCNT};

uint16_t reg[RCNT] = {0};


#define OPC(i) ((i)>>12)

#define NOPS (16) // number of opcodes

typedef void (*op_ex_fn)(uint16_t instruction);


static inline void add (uint16_t i) {}

static inline void and (uint16_t i) {}

op_ex_fn op_ex[NOPS] = {
    br,add,ld,st,jsr,and,ldr,str,rti,not,ldi,sti,jmp,res,lea,trap
};


uint16_t instr = ...;

op_ex[OP(instr)](instr);


