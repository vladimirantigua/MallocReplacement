//
//  MallocReplace.cpp
//  WritingMallocReplacement
//
//  Created by Vladimir Antigua on 3/17/21.
//

#include <unistd.h>
#include <stdlib.h>
#include <sys/mman.h>
#include "MallocReplace.hpp"

//Constructor
MallocReplace::MallocReplace(){
    pageSize = getpagesize();
    
}
//Destructor
MallocReplace::~MallocReplace(){
    
}

//hash table insert, delete, grow
HashTable MallocReplace::getTable(){
    
    return table;
}


void* MallocReplace::allocate(size_t bytesToAllocate){
    void* pointer =  mmap(NULL, bytesToAllocate, PROT_READ | PROT_WRITE | PROT_EXEC, MAP_ANONYMOUS | MAP_PRIVATE, 0, 0); // 0 means file descriptor read, 0 = offset
    
    if(pointer == MAP_FAILED){
//        report and error:
        perror("MMAP Allocation fail.");
        exit(1);
    }
    table.insert(pointer, bytesToAllocate);
    
    return pointer;
}

void MallocReplace::deallocate(void* ptr){
    if(munmap(ptr, table.get(ptr)) != 0){
        // report and error:
//        perror("munmap De-allocation fail.");

    }
    
    table.remove(ptr); // remove pointer from the table
}

