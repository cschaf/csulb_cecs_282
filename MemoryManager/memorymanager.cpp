#include "MemoryManager.h"
#include <iostream>
#include <iomanip>

using namespace std;

namespace MemoryManager

{

    // IMPORTANT IMPORTANT IMPORTANT IMPORTANT IMPORTANT IMPORTANT IMPORTANT

    //

    // This is the only static memory that you may use, no other global variables

    // may be created, if you need to save data make it fit in MM_pool

    //

    // IMPORTANT IMPORTANT IMPORTANT IMPORTANT IMPORTANT IMPORTANT IMPORTANT

    const int MM_POOL_SIZE = 65536;

    char MM_pool[MM_POOL_SIZE];

    // I have provided this tool for your use

    void memView(int start, int end)
    {

        const unsigned int SHIFT = 8;

        const unsigned int MASK = 1 << SHIFT - 1;

        unsigned int value; // used to facilitate bit shifting and masking

        cout << " Pool Unsignd Unsigned " << endl;

        cout << "Mem Add indx bits chr ASCII# short int " << endl;

        cout << "-------- ---- -------- --- ------ ------- ------------" << endl;

        for (int i = start; i <= end; i++)

        {

            cout << (long*)(MM_pool + i) << ':'; // the actual address in hexadecimal

            cout << '[' << setw(2) << i << ']'; // the index into MM_pool

            value = MM_pool[i];

            cout << " ";

            for (int j = 1; j <= SHIFT; j++) // the bit sequence for this byte (8 bits)

            {

                cout << ((value & MASK) ? '1' : '0');

                value <<= 1;

            }

            cout << " ";

            cout << '|' << *(char*)(MM_pool + i) << "| ("; // the ASCII character of the 8 bits (1 byte)

            cout << setw(4) << ((int)(*((unsigned char*)(MM_pool + i)))) << ")"; // the ASCII number of the character

            cout << " (" << setw(5) << (*(unsigned short*)(MM_pool + i)) << ")"; // the unsigned short value of 16 bits (2 bytes)

            cout << " (" << setw(10) << (*(unsigned int*)(MM_pool + i)) << ")"; // the unsigned int value of 32 bits (4 bytes)

            cout << endl;

        }

    }

    // Initialize set up any data needed to manage the memory pool

    void initializeMemoryManager(void)

    {
        int freeHead = 0;
        int inUseHead = 2;
        int usedHead = 4;

        *(unsigned short*)(MM_pool + freeHead) = 6;
        *(unsigned short*)(MM_pool + 6) = MM_POOL_SIZE - 6;
        *(unsigned short*)(MM_pool + inUseHead) = 0;
        *(unsigned short*)(MM_pool + usedHead) = 0;
    }



    // return a pointer inside the memory pool

    // If no chunk can accommodate aSize call onOutOfMemory() - still

    void* allocate(int aSize)
    {
        unsigned short freeHead = *((unsigned short*)MM_pool);
        if(freeHead + aSize + 6 > MM_POOL_SIZE - 6) onOutOfMemory();
        else{
            *((unsigned short*)(MM_pool + freeHead)) = aSize;
            *((unsigned short*)MM_pool) = aSize + 6 + *((unsigned short*)MM_pool);

            unsigned short *currentNode = (unsigned short*)(MM_pool + freeHead);
            unsigned short *firstNode = (unsigned short*)(MM_pool + (*(unsigned short*)(MM_pool + 2)));

            if (*((unsigned short*)(MM_pool + 2)) == 0){
                *(currentNode + 1) = 0;
                *(currentNode + 2) = 0;
            }
            else{
                *(currentNode + 1) = *((unsigned short*)(MM_pool + 2));
                *(currentNode + 2) = 0;
                *(firstNode + 2) = freeHead;
            }
            *((unsigned short*)(MM_pool + 2)) = freeHead;
            return (void*)(MM_pool + freeHead + 6);
        }
        return NULL;
    }

    // Free up a chunk previously allocated

    void deallocate(void* aPointer){
        unsigned short *usedPtr = (unsigned short*)(MM_pool + (*(unsigned short*)(MM_pool + 4)));
        int used = (*(unsigned short*)(MM_pool + 4));
        unsigned short *currentNode = ((unsigned short*) aPointer) - 3;
        unsigned short *prevNode = (unsigned short*)(MM_pool + *(currentNode + 2));
        unsigned short *nextNode = (unsigned short*)(MM_pool + *(currentNode + 1));

        if (*((unsigned short*)(MM_pool + 4)) == 0){
            *(unsigned short*)(MM_pool + 4) = *(prevNode + 1);
            *(prevNode + 1) = *(currentNode + 1);
            *(nextNode + 2) = *(currentNode + 2);
            *(currentNode + 2) = 0;
            *(currentNode + 1) = 0;
        }
        else{
            if (*(currentNode + 1) == 0 && *(currentNode + 2) == 0){
                *(unsigned short*)(MM_pool+4) = *(unsigned short*)(MM_pool + 2);
                *(unsigned short*)(MM_pool + 2) = 0;
                *(currentNode + 1) = used;
                *(currentNode + 2) = 0;
            }
            else{
                if (*(currentNode + 2) != 0){
                    *(unsigned short*)(MM_pool + 4) = *(prevNode + 1);
                    *(prevNode + 1) = *(currentNode + 1);
                }
                else{
                    *(unsigned short*)(MM_pool + 2) = *(currentNode + 1);
                    *(unsigned short*)(MM_pool + 4) = *(nextNode + 2);

                }
                *(usedPtr + 2) = *(unsigned short*)(MM_pool + 4);
                if (*(currentNode + 1) != 0){
                    *(nextNode + 2) = *(currentNode + 2);
                }
                else{
                    *(prevNode + 1) = *(currentNode + 1);
                }
                *(currentNode + 1) = used;
                *(currentNode + 2) = 0;
            }
        }
    }

    //---

    //--- support routines

    //---

    // Will scan the memory pool and return the total free space remaining

    int freeMemory(void){
        return MM_POOL_SIZE - inUseMemory() - 6 - usedMemory();
    }

    // Will scan the memory pool and return the total deallocated memory

    int usedMemory(void){
        int counter = 0;
        int size = 0;
        unsigned short *currentNode = (unsigned short*)(MM_pool + *(unsigned short*)(MM_pool + 4));
        if (*(MM_pool + 4) == 0){
            return size;
        }
        else{
            while (true){
                size += *(currentNode);
                counter++;
                if (*(currentNode + 1) == 0){
                    break;
                }
                currentNode = (unsigned short*)(MM_pool + *(currentNode + 1));
            }
        }
        return size + counter*6;
    }

    // Will scan the memory pool and return the total in use memory

    int inUseMemory(void){
        int counter = 0;
        int size = 0;
        unsigned short *currentNode = (unsigned short*)(MM_pool + *(unsigned short*)(MM_pool + 2));

        if (*(unsigned short*)(MM_pool + 2) == 0){
            return size;
        }
        else{
            while (true){
                size += *(currentNode);
                counter++;
                if (*(currentNode + 1) == 0){
                    break;
                }
                currentNode = (unsigned short*)(MM_pool + *(currentNode + 1));
            }
        }
        return size + counter*6;
    }

    void onOutOfMemory()
    {
        std::cout<<"Out of memory!"<<std::endl;
    }

}
