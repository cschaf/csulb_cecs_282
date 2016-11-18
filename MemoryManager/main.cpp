#include <iostream>

using namespace std;

int main()
{    
    // Problems
    // I dont know the size of a block
    // we need links (double linked list, one element knows his next and previous)
    //

    initializeMemoryManager();
    int start = freeMemory(); // 65530
    short* shortPtr = (short*)allocate(sizeof(short));

    return 0;
}
