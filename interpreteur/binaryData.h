#ifndef BINARY_DATA
#define BINARY_DATA

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct block 
{
    int segSize;
    int vBaseAdress;
    int vMaxAdress;
    struct block* nextBlock;
    struct block* prevBlock;
    uint8_t* data;
} BinaryBlock;

// creation and destruction of blocks
BinaryBlock* newBlock(size_t nbSeg, int segSize);
void clearBlock(BinaryBlock* block);
void clearData(BinaryBlock* block);

// add a block at the end of the CodeBlock
// return the added block
BinaryBlock* addBlock(BinaryBlock* prevBlock, size_t nbSeg);


// get a line of code from the adress
uint8_t* readingSegment(BinaryBlock* block, int adress);

// set a line of code at the adress, return the block where the data are written
BinaryBlock* writeSegment(BinaryBlock* block, int adress, uint8_t* data);


#endif