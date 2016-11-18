#include "memorymanager.h"

MemoryManager::MemoryManager()
{
    nextFreeMemoryIndex = 6;
    inUseHead = 0;
    usedHead = 0;
}
