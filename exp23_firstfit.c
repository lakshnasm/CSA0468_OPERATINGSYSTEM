#include <stdio.h>

#define MAX_MEMORY 1000

int memory[MAX_MEMORY];

void initializeMemory()
{
    for(int i=0;i<MAX_MEMORY;i++)
        memory[i]=-1;
}

void allocateMemory(int processId,int size)
{
    int start=-1;
    int blockSize=0;

    for(int i=0;i<MAX_MEMORY;i++)
    {
        if(memory[i]==-1)
        {
            if(blockSize==0)
                start=i;

            blockSize++;
        }
        else
            blockSize=0;

        if(blockSize>=size)
            break;
    }

    if(blockSize>=size)
    {
        for(int i=start;i<start+size;i++)
            memory[i]=processId;

        printf("Allocated memory block %d-%d\n",
               start,start+size-1);
    }
}

int main()
{
    initializeMemory();
    return 0;
}
