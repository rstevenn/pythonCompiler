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
    
    uint8_t* pc;
    uint8_t* sp;
    uint8_t* ra;

    uint8_t* r0;
    uint8_t* r1;
    uint8_t* r2;
    uint8_t* r3;
    uint8_t* r4;
    uint8_t* r5;
    uint8_t* r6;
    uint8_t* r7;
    uint8_t* r8;
    uint8_t* r9;
    
} Registers;

typedef struct data
{
    Registers* regs;
    Pages* pages;
    BinaryBlock* stack;
} InterpertreData;

Registers* newRegisters(void);
void clearRegisters(Registers* regs);

Pages* newPages(void);
void clearPages(Pages* pages);

BinaryBlock* newStack(void);
void clearStack(BinaryBlock* block);

int allocate(int size, Pages* memory);
int reAllocate(int size, Pages* memory, int adress);
void freeMem(Pages* page, int adress);
void secureFree(Pages* page, int adress);

#endif