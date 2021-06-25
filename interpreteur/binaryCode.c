#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "binaryCode.h"
#include "binaryData.h"

BinaryBlock* newCodeSpace(int nbLine)
{
    return newBlock(nbLine, CODE_LINE_SIZE);
}

BinaryBlock* addCodeBlock(BinaryBlock* block, int nbLine)
{
    return addBlock(block, nbLine);
}

uint8_t* getCodeLine(BinaryBlock* block, int adress)
{
    return readingSegment(block, adress);
}

BinaryBlock* setCodeLine(BinaryBlock* block, int adress, uint8_t* code)
{
    return writeSegment(block, adress, code);
}