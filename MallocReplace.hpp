//
//  MallocReplace.hpp
//  WritingMallocReplacement
//
//  Created by Vladimir Antigua on 3/17/21.
//

#ifndef MallocReplace_hpp
#define MallocReplace_hpp

#include <stdio.h>
#include "HashTable.hpp"

class MallocReplace {
public:
    
    void* allocate(size_t bytesToAllocate);

    void deallocate(void* ptr);
    
//    Constructor/Destructor
    
    //Constructor
    MallocReplace();
    
    //Destructor
    ~MallocReplace();
    
    //hash table insert, delete, grow
    HashTable getTable();
    
private:
    size_t pageSize; // to keep track page size
    HashTable table; // to keep track table
    
};



#endif /* MallocReplace_hpp */
