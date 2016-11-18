#ifndef MEMORYMANAGER_H
#define MEMORYMANAGER_H


class MemoryManager
{
public:
    MemoryManager();
    void* allocate(int);
    void deallocate(void*);

private:
    short nextFreeMemoryIndex; // index 0
    short inUseHead; // index 2
    short usedHead; // index 4
};

#endif // MEMORYMANAGER_H
