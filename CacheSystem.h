
//Header file for Cache System i.e. Memory Hierarchy Simulator

#ifndef CACHESYSTEM_H
#define CACHESYSTEM_H

#include "CacheLevel.h"

class CacheSystem{
    public:
    CacheLevel L1;
    CacheLevel L2;
    CacheLevel L3;
    static inline int RAM_access=0;
    
    CacheSystem();

    void promote_to_L1(std::string mem, CacheLevel &L1, CacheLevel &L2, CacheLevel &L3);  
    
    void print();

    int access(std::string mem);


};

#endif