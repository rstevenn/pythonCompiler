#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "interpret.h"
#include "binaryCode.h"
#include "binaryData.h"

Registers* newRegisters(void)
{
    Registers* regs = (Registers*)malloc(sizeof(Registers));
    if (regs == NULL)
    {
        printf("[-] Error while creating a Registe (regs), memory allocation\n");
        exit(1);
    }

    regs->pc = (uint8_t*) malloc(ENCODING);
    if (regs->pc == NULL)
    {
        printf("[-] Error while creating a Registe (regs->pc), memory allocation\n");
        exit(1);
    }

    regs->sp = (uint8_t*) malloc(ENCODING);
    if (regs->sp == NULL)
    {
        printf("[-] Error while creating a Registe (regs->sp), memory allocation\n");
        exit(1);
    }

    regs->ra = (uint8_t*) malloc(ENCODING);
    if (regs->ra == NULL)
    {
        printf("[-] Error while creating a Registe (regs->ra), memory allocation\n");
        exit(1);
    }
    
    regs->r0 = (uint8_t*) malloc(ENCODING);
    if (regs->r0 == NULL)
    {
        printf("[-] Error while creating a Registe (regs->r0), memory allocation\n");
        exit(1);
    }
    
    regs->r1 = (uint8_t*) malloc(ENCODING);
    if (regs->r1 == NULL)
    {
        printf("[-] Error while creating a Registe (regs->r1), memory allocation\n");
        exit(1);
    }
    
    regs->r2 = (uint8_t*) malloc(ENCODING);
    if (regs->r2 == NULL)
    {
        printf("[-] Error while creating a Registe (regs->r2), memory allocation\n");
        exit(1);
    }
    
    regs->r3 = (uint8_t*) malloc(ENCODING);
    if (regs->r3 == NULL)
    {
        printf("[-] Error while creating a Registe (regs->r3), memory allocation\n");
        exit(1);
    }
    
    regs->r4 = (uint8_t*) malloc(ENCODING);
    if (regs->r4 == NULL)
    {
        printf("[-] Error while creating a Registe (regs->r4), memory allocation\n");
        exit(1);
    }
    
    regs->r5 = (uint8_t*) malloc(ENCODING);
    if (regs->r5 == NULL)
    {
        printf("[-] Error while creating a Registe (regs->r5), memory allocation\n");
        exit(1);
    }
    
    regs->r6 = (uint8_t*) malloc(ENCODING);
    if (regs->r6 == NULL)
    {
        printf("[-] Error while creating a Registe (regs->r6), memory allocation\n");
        exit(1);
    }
    
    regs->r7 = (uint8_t*) malloc(ENCODING);
    if (regs->r7 == NULL)
    {
        printf("[-] Error while creating a Registe (regs->r7), memory allocation\n");
        exit(1);
    }
    
    regs->r8 = (uint8_t*) malloc(ENCODING);
    if (regs->r8 == NULL)
    {
        printf("[-] Error while creating a Registe (regs->r8), memory allocation\n");
        exit(1);
    }
    
    regs->r9 = (uint8_t*) malloc(ENCODING);
    if (regs->r9 == NULL)
    {
        printf("[-] Error while creating a Registe (regs->r9), memory allocation\n");
        exit(1);
    }
    

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
    if (pages == NULL)
    {
        printf("[-] Error while creating a new dataPage, memory allocation\n");
        exit(1);
    }
    
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

    if (memory->pages == NULL)
    {
        printf("[-] Error while allocating pages (memory->pages), memory allocation\n");
        exit(1);
    }

    if (memory->headers == NULL)
    {
        printf("[-] Error while allocating pages (memory->headers), memory allocation\n");
        exit(1);
    }
    
    
    /*
    Basicly create new pages as a naive way of allocating memory 
    */
    for (int i = 0; i < nbPages; i++)
    {

        
    }

    return vAdress;
}