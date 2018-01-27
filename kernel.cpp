//main kernel function
void printf(char* str)
{
    //hard coded Video Memory address
    unsigned short* VideoMemory = (unsigned short*)0xb8000;
    //srcpy from the pointer
    for(int i=0;str[i] !=0; ++i)
      VideoMemory[i]= (VideoMemory[i] & 0xFF00) | str[i];//0xFF00 is the less significant part of the video mem bytes, meaning the color for background and foreground
  
 }

//@params accepting values on top of stack
//extern "C" makes function available for linker
extern "C" void kernelMain(void* multiboot_structure, unsigned int magicnumber)
{
  printf("Hello");
  while(1);
}
