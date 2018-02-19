#include "types.h"
#include "gdt.h"

//main kernel function
void printf(char* str)
{
    //hard coded Video Memory address
    uint16_t* VideoMemory = ( uint16_t* )0xb8000;
    //srcpy from the pointer
    for(int i=0;str[i] !=0; ++i)
      VideoMemory[i]= (VideoMemory[i] & 0xFF00) | str[i];//0xFF00 is the less significant part of the video mem bytes, meaning the color for background and foreground
  
 }

typedef void (*constructor)();
extern "C" constructor start_ctors;
extern "C" constructor end_ctors;
extern "C" void callConstructors()
{
	for( constructor* i = &start_ctors ; i != &end_ctors ; i++ )
	(*i)();
}

//params accepting values on top of stack
//extern "C" makes function available for linker
extern "C" void kernelMain(void* multiboot_structure, uint32_t magicnumber)
{
  printf("We are now in kernel main");
  while(1);
}
