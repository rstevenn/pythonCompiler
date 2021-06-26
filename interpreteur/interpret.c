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
    
    return regs;
} 


void clearRegisters(Registers* regs)
{
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