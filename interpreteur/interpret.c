#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "interpret.h"
#include "binaryCode.h"
#include "binaryData.h"


Registers* newRegisters(void)
{
    Registers* regs = (Registers*)malloc(sizeof(Registers));

    regs->pc = (uint8_t*) malloc(ENCODING);
    regs->sp = (uint8_t*) malloc(ENCODING);
    regs->ra = (uint8_t*) malloc(ENCODING);

    regs->r0 = (uint8_t*) malloc(ENCODING);
    regs->r1 = (uint8_t*) malloc(ENCODING);
    regs->r2 = (uint8_t*) malloc(ENCODING);
    regs->r3 = (uint8_t*) malloc(ENCODING);
    regs->r4 = (uint8_t*) malloc(ENCODING);
    regs->r5 = (uint8_t*) malloc(ENCODING);
    regs->r6 = (uint8_t*) malloc(ENCODING);
    regs->r7 = (uint8_t*) malloc(ENCODING);
    regs->r8 = (uint8_t*) malloc(ENCODING);
    regs->r9 = (uint8_t*) malloc(ENCODING);

    return regs;
} 


void clearRegisters(Registers* regs)
{
    free(regs->pc);
    free(regs->sp);
    free(regs->ra);

    free(regs->r0);
    free(regs->r1);
    free(regs->r2);
    free(regs->r3);
    free(regs->r4);
    free(regs->r5);
    free(regs->r6);
    free(regs->r7);
    free(regs->r8);
    free(regs->r9);

    free(regs);
}

Pages* newPages(void)
{
    Pages* pages = (Pages*) malloc(sizeof(Pages));
    pages->nbPages = 0;
    pages->nbFreePages = 0;
    pages->pages = NULL;
    pages->headers = NULL;

    return pages;
}

void clearPages(Pages* pages)
{
    free(pages->pages);
    free(pages->headers);
    free(pages);
}

BinaryBlock* newStack(void)
{
    return newBlock(8, STACK_SIZE);
}

void clearStack(BinaryBlock* block)
{
    clearData(block);
}

int allocate(int size, Pages* memory)
{
    int vAdress;
    int nbPages = size / (PAGES_SIZE * PAGES_SEG_SIZE);

    if(size%(PAGES_SIZE * PAGES_SEG_SIZE) != 0)
    {
        nbPages++;
    }

    if (memory->nbPages == 0)
    {
        memory->pages = (Page*)malloc(sizeof(Page) * nbPages);
        memory->headers = (PageHeader*)malloc(sizeof(PageHeader) *  nbPages);
    } else {
        memory->pages = (Page*)realloc(memory->pages, sizeof(Page) * (memory->nbPages + nbPages));
        memory->headers = (PageHeader*)realloc(memory->headers, sizeof(PageHeader) * (memory->nbPages + nbPages));
    }
    /*
    Basicly create new pages as a naive way of allocating memory 
    */
    for (int i = 0; i < nbPages; i++)
    {

        
    }

    return vAdress;
}