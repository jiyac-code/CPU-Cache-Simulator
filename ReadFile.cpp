#include <iostream>
#include <sstream>
#include <fstream>
#include "ReadFile.h"

using namespace std;

vector<Task> readfile(const string& filename){
    vector<Task> tasks;

    ifstream fin(filename);
    string str,dummy;

    while(fin>>str){
        if(str=="TASK"){
            Task t;
            fin>>t.id;
        
            fin>>dummy;
            fin>>t.burst_time;
            t.remaining_time=t.burst_time;

            fin>>dummy;

            string line;
            getline(fin,line);
            string memory;
            stringstream ss(line);
            while(ss>>memory){
                t.MEM.push_back(memory);        //stores each memory block in the vector 'MEM' for each task
            }

            tasks.push_back(t);                 //pushes the task object into the vector 'tasks'
        }
    }

    return tasks;
}