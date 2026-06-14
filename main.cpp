
//Main file
//CPU Scheduler and Memory Cache Simulator

#include <iostream>
#include "ReadFile.h"
#include "CacheSystem.h"
#include "RoundRobin.h"
#include "Task.h"

using namespace std;

int main() {
    vector<Task> tasks=readfile("input_task2.txt");
    CacheSystem cache;
    RoundRobin(tasks,cache);
}