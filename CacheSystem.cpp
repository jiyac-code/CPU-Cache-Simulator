#include <iostream>
#include "CacheSystem.h"

using namespace std;

    CacheSystem::CacheSystem(): L1(3,"L1"), L2(5,"L2"), L3(8,"L3"){}                                    //Initialized 3 cache memory levels with their respective capacities

    void CacheSystem::promote_to_L1(string mem, CacheLevel &L1, CacheLevel &L2, CacheLevel &L3){        //Function to promote a memory block into L1
        cout<<endl;
        string evictedL1=L1.insert(mem);
        if(evictedL1!=""){
            cout<<"Oldest memory block evicted from L1 into L2"<<endl;
            string evictedL2= L2.insert(evictedL1);
            if(evictedL2!=""){
                cout<<"Oldest memory block evicted from L2 into L3"<<endl;
                string evictedL3=L3.insert(evictedL2);
                if(evictedL3!=""){
                    cout<<"Oldest memory block evicted from L3"<<endl;
                }
            }
        }
    }

    void CacheSystem::print(){
        cout<<endl;
        L1.display();
        cout<<endl;
        L2.display();
        cout<<endl;
        L3.display();
        cout<<endl<<endl<<endl;
    }

    int CacheSystem::access(string mem){        //access a memory block from the cache level
        if(L1.search(mem)){
            L1.display();
            cout<<" ->HIT"<<endl;
            print(); 
            return 4;
        }

        else if(L2.search(mem)){
            L1.display();
            cout<<" >>MISS"<<endl;
            L2.display();
            cout<<" ->HIT"<<endl;

            cout<<"\nPromoting "<<mem<<" from L2 to L1";
            L2.remove(mem);
            promote_to_L1(mem,L1,L2,L3);
            print();
            return 12;
        }
        
        else if(L3.search(mem)){
            L1.display();
            cout<<" >>MISS"<<endl;
            L2.display();
            cout<<" >>MISS"<<endl;
            L3.display();
            cout<<" ->HIT"<<endl;

            cout<<"\nPromoting "<<mem<<" from L3 to L1";
            L3.remove(mem);
            promote_to_L1(mem,L1,L2,L3);
            print();
            
            return 40;
        }

        else{
            L1.display();
            cout<<" >>MISS"<<endl;
            L2.display();
            cout<<" >>MISS"<<endl;
            L3.display();
            cout<<" >>MISS"<<endl;
            cout<<"\nFetching from RAM"<<endl;
            RAM_access++;
            cout<<"Promoting to L1";
            promote_to_L1(mem,L1,L2,L3);
            print();
            return 200;
        }
    }

