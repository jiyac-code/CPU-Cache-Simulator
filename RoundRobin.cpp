#include <iostream>
#include "RoundRobin.h"

using namespace std;

void RoundRobin(vector<Task> tasks, CacheSystem cache){
    int quantum=3;
    int cycle=0;
    int total_latency=0;

    queue<int> ready;
    for(int i=0; i<tasks.size();i++){
        ready.push(i);             //insert all tasks into ready queue initially
    }

    while(!ready.empty()){
        int idx=ready.front();
        ready.pop();

        Task &t=tasks[idx];
        int process_time=min(quantum,t.remaining_time);     //will decide how many cycles the task runs for

        for(int i=0; i<process_time; i++){
            cycle++;

            cout<<"\033[1;4m"<<"Cycle "<<cycle<<" running: "<<t.id<<" "<<"\033[0m";
            if(t.mem_idx==t.MEM.size()){
                cout<<"\nCPU executes"<<endl;
                cout<<endl;
                t.remaining_time--;
                continue;
            }

            string mem = t.MEM[t.mem_idx];

            cout<<"\033[1;4m"<<"Requesting "<<mem<<"\033[0m"<<endl;

            int latency=cache.access(mem);
            total_latency+=latency;

            t.mem_idx++;
            t.remaining_time--;
        }
        if(t.remaining_time>0){             //push the task back into 'ready' queue if task is not completed
            ready.push(idx);
        }
    }

    cout<<"End of Tasks"<<endl;
    cout<<"=== Final Results ==="<<endl;
    cout<<"CPU cycles: "<<cycle<<endl;
    cout<<"Memory Latency: "<<total_latency<<endl;
    cout<<"Total cycles: "<<cycle+total_latency<<endl;
    cout<<"Tasks completed: "<<tasks.size()<<endl;
    cout<<"Scheduler: Round Robin (quantum = "<<quantum<<")"<<endl;
    cout<<"RAM Accesses: "<<CacheSystem::RAM_access;

}