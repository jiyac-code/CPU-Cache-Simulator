
//Header file for Cache Levels

#ifndef CACHELEVEL_H
#define CACHELEVEL_H

#include <string>
#include <queue>

class CacheLevel{
    int capacity;
    std::string id;
    std::queue<std::string> level;
    
    public:
    CacheLevel(int cap,std::string i);

    bool search(std::string mem);

    std::string evict();


    std::string insert(std::string mem);

    void remove(std::string mem);

    void display();
};

#endif