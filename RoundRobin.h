
//Header file for Round Robin scheduling algorithm

#ifndef ROUNDROBIN_H
#define ROUNDROBIN_H

#include "Task.h"
#include "CacheSystem.h"
#include <vector>
#include <queue>
#include <algorithm>

void RoundRobin(std::vector<Task> tasks, CacheSystem cache);

#endif