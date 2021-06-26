#ifndef INTERPRET
#define INTERPRET

#include "binaryCode.h"
#include "binaryData.h"

#define PAGES_SIZE 64
#define PAGES_SEG_SIZE 8
#define STACK_SIZE 65536

typedef struct pheader {
    int index;
    int allocated: 1;
    struct pheader* nextHeader;
    int vBaseAdress;
    int vMaxAdress;
} PageHeader;


typedef struct page{
    uint8_t* data;
} Page;

typedef struct pages
{
    int nbPages;
    int nbFreePages;
    Page* pages;
    PageHeader* headers;
} Pages;

typedef struct registers {
    
    uint8_t pc[ENCODING/8];
    uint8_t sp[ENCODING/8];
    uint8_t ra[ENCODING/8];

    uint8_t r0[ENCODING/8];
    uint8_t r1[ENCODING/8];
    uint8_t r2[ENCODING/8];
    uint8_t r3[ENCODING/8];
    uint8_t r4[ENCODING/8];
    uint8_t r5[ENCODING/8];
    uint8_t r6[ENCODING/8];
    uint8_t r7[ENCODING/8];
    uint8_t r8[ENCODING/8];
    uint8_t r9[ENCODING/8];
    
} Registers;

typedef struct data
{
    Registers* regs;
    Pages* pages;
    BinaryBlock* stack;
} InterpretreData;

Registers* newRegisters(void);
void clearRegisters(Registers* regs);

Pages* newPages(void);
void clearPages(Pages* pages);

BinaryBlock* newStack(void);
void clearStack(BinaryBlock* block);

InterpretreData* newIData(void);
void clearIData(InterpretreData* data);

int allocate(int size, Pages* memory);
int reAllocate(int size, Pages* memory, int adress);
void freeMem(Pages* page, int adress);
void secureFree(Pages* page, int adress); // same as free meme, but put the rewrite garbage on the allocated memore

#endif