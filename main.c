#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "interpreteur/binaryData.h"
#include "interpreteur/binaryCode.h"
#include "interpreteur/interpret.h"

int main(int argc, char* argv[])
{
    BinaryBlock* block = newCodeSpace(64);
    BinaryBlock* nBlock = block;
    
    printf("[+] CodeBlock created with sucess, virtual adress %x-%x real adress %x-%x\n",
            block->vBaseAdress, 
            block->vMaxAdress, 
            (unsigned int) block->data, 
            (unsigned int) block->data + (nBlock->vMaxAdress - nBlock->vBaseAdress));

    for (int i = 0; i < 9; i++)
    {
        nBlock = addCodeBlock(nBlock, 65536);
        printf("[+] new block added at the virtual adress %x-%x real adress %x-%x\n", 
                nBlock->vBaseAdress, 
                nBlock->vMaxAdress, 
                (unsigned int) nBlock->data, 
                (unsigned int) nBlock->data + (nBlock->vMaxAdress - nBlock->vBaseAdress));
    }

    int adress = CODE_LINE_SIZE * 64 * 20 + CODE_LINE_SIZE * 63;

    uint8_t* code = malloc(CODE_LINE_SIZE);
    for (int i = 0; i < CODE_LINE_SIZE/8; i++)
    {
        code[i] = i%255;
    }   
    setCodeLine(block, adress, code);
    printf("[+] Line %x write with sucess: ", adress);

    for (int i = 0; i < CODE_LINE_SIZE/8; i++)
    {
        printf("%x", code[i]);
    }

    printf("\n");


    uint8_t* line = getCodeLine(block, adress);
    printf("[+] Line %x read with sucess: ", adress);

    for (int i = 0; i < CODE_LINE_SIZE/8; i++)
    {
        printf("%x", line[i]);
    }

    printf("\n");

    clearData(block);
    printf("[+] CodeBlock destroyed with sucess\n");


    InterpretreData* idat = newIData();
    printf("[+] InterpretreData created with sucess\n");
    clearIData(idat);
    printf("[+] InterpretreData destroyed with sucess\n");

    return 0;
}