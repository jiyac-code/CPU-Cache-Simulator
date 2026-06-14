#include <iostream>
#include "CacheLevel.h"

using namespace std;

    CacheLevel::CacheLevel(int cap,string i){
        capacity=cap;
        id=i;
    }

    bool CacheLevel::search(string mem){    // search for a memory block in a cache level
        queue<string> temp(level);
        while(!temp.empty()){
            if (mem==temp.front())
            {return true;}
            temp.pop();
        }
        return false;
    }


    string CacheLevel::evict(){
        string oldest=level.front();
        level.pop();
        return oldest;                      // returns evicted memory block
    }


    string CacheLevel::insert(string mem){  // insert the memory block in the cache level 
        if(CacheLevel::search(mem))
            {return "";}

        string evicted="";

        if(level.size()>=capacity){         // return evicted memory block if cache level is full
            evicted=evict();}

        level.push(mem);
        return evicted;
    }

    void CacheLevel::remove(string mem){    // remove a memory block from cache level
        queue<string> temp;

        while(!level.empty()){
            if(mem!=level.front()){
                temp.push(level.front());
            }
            level.pop();
        }

        level=temp;
    }

    void CacheLevel::display(){             // display memory contents of cache level
        queue<string> temp(level);
        cout<<id<<": ";
        cout<<'[';
        while(!temp.empty()){
            cout<<temp.front();
            temp.pop();
            if(!temp.empty())
            {cout<<',';}
        }
        cout<<']';
    }
