#include "binaryData.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

BinaryBlock* newBlock(size_t nbSeg, int segSize)
{

    if (segSize <= 0 || segSize%8 != 0)
    {
        printf("[-] Error while creating a new memory space, the segment size %x must be > 0 and must be a multiple of 8\n", segSize);
        exit(1);
    }

    BinaryBlock* block = (BinaryBlock*)malloc(sizeof(BinaryBlock));
    if (block == NULL)
    {
        printf("[-] Error while creating a Block (block), memory allocation\n");
    }

    block->segSize = segSize;
    block->vBaseAdress = 0;
    block->vMaxAdress = segSize * nbSeg - 1;
    block->nextBlock = NULL;
    block->prevBlock = NULL;
    block->data = (uint8_t*)malloc(segSize * nbSeg);

    if (block->data == NULL)
    {
        printf("[-] Error while creating a Block (block->data), memory allocation\n");
    }

    return block;
}

void clearBlock(BinaryBlock* block)
{
    if (block->nextBlock != NULL)
    {
        block->nextBlock->prevBlock = block->prevBlock;
    }

    if (block->prevBlock != NULL)
    {
        block->prevBlock->nextBlock = block->nextBlock;
    }

    free(block->data);
    free(block);
}

void clearData(BinaryBlock* block)
{

    while (block->nextBlock != NULL)
    {
        clearBlock(block->nextBlock);
    }

    while (block->prevBlock != NULL)
    {
        clearBlock(block->prevBlock);
    }

    clearBlock(block);   

}

BinaryBlock* addBlock(BinaryBlock* prevBlock, size_t nbSeg)
{
    while (prevBlock->nextBlock != NULL)
    {
        prevBlock = prevBlock->nextBlock;
    }


    BinaryBlock* block = (BinaryBlock*) malloc(sizeof(BinaryBlock));
    if (block == NULL)
    {
        printf("[-] Error while adding a Block, memory allocation\n");
    }

    block->segSize = prevBlock->segSize;
    block->vBaseAdress = prevBlock->vMaxAdress + 1;
    block->vMaxAdress = block->vBaseAdress + nbSeg * prevBlock->segSize -1;
    block->nextBlock = NULL;
    block->prevBlock = prevBlock;
    block->data = malloc(nbSeg * prevBlock->segSize);
    if (block->data == NULL)
    {
        printf("[-] Error while adding a Block (block->data), memory allocation\n");
    }

    prevBlock->nextBlock = block;

    return block;
}


uint8_t* readingSegment(BinaryBlock* block, int adress)
{
    uint8_t* data = malloc(block->segSize);
    if (data == NULL)
    {
        printf("[-] Error while reading segment, memory allocation\n");
    }

    while (block->vMaxAdress < adress)
    {

        if (block->nextBlock == NULL)
        {
            printf("[-] Error while reading segment, adress %x must be less than %x", adress, block->vMaxAdress);
            exit(1);
        }

        block = block->nextBlock;


    }

    while (block->vBaseAdress > adress)
    {
        if (block->prevBlock == NULL)
        {
            printf("[-] Error while reading segment, adress %x must be greater than %x", adress, block->vBaseAdress);
            exit(1);
        }
        block = block->prevBlock;

    }


    for(int i = 0; i < block->segSize/8; i++)
    {
        data[i] = block->data[(adress - block->vBaseAdress) / 8 + i];
    }
    return data;
}

BinaryBlock* writeSegment(BinaryBlock* block, int adress, uint8_t* data)
{

    while (block->vMaxAdress < adress)
    {

        if (block->nextBlock == NULL)
        {
            printf("[-] Error while writing segment, adress %x must be less than %x", adress, block->vMaxAdress);
            exit(1);
        }

        block = block->nextBlock;


    }

    while (block->vBaseAdress > adress)
    {
        if (block->prevBlock == NULL)
        {
            printf("[-] While writing segment, adress %x must be greater than %x", adress, block->vBaseAdress);
            exit(1);
        }
        block = block->prevBlock;

    }

    for(int i = 0; i < block->segSize/8; i++)
    {
        block->data[(adress - block->vBaseAdress) / 8 + i] = data[i];
    }

    return block;
}