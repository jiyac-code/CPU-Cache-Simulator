
//Header file for tasks

#ifndef TASK_H
#define TASK_H

#include <vector>
#include <string>

class Task{
    public:
    std::string id;
    int burst_time;
    int remaining_time;
    int mem_idx=0;
    std::vector<std::string> MEM;
};

#endif
