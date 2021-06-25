#ifndef BINARY_CODE
#define BINARY_CODE
#define ENCODING 64
#define CODE_LINE_SIZE (8+3*ENCODING)

#include <stdint.h>
#include "binaryData.h"


BinaryBlock* newCodeSpace(int nbLine);

BinaryBlock* addCodeBlock(BinaryBlock* block, int nbLine);

uint8_t* getCodeLine(BinaryBlock* block, int adress);

BinaryBlock* setCodeLine(BinaryBlock* block, int adress, uint8_t* code);

#endif