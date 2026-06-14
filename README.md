# README

## CPU-Cache Simulator

### Overview
This is a CPU Scheduler and Memory Cache Simulator implemented in C++. It simulates how tasks get allocated to a CPU and how memory blocks move through a cache hierarchy. It makes use of Round Robin scheduling algorithm. This was developed for Xplore Summer Mentorship Program 2026 - Task 2.

***

### Features

#### CPU Scheduler
- Round Robin Scheduling Algorithm
- Tracks each cycle
- Displays the running task at every cycle

#### Cache Hierarchy
- Three cache levels (for simulation purpose, their capacities are listed below):
    - L1 (3)
    - L2 (5)
    - L3 (8)
- Shows cache hit/miss
- FIFO eviction policy
- Automatic promotion on cache hit
- Real-time cache state visualization

#### Statistics
Displays:
- CPU cycles
- Memory latency
- Total CPU cycles (i.e CPU cycles + Memory latency)
- Tasks completed
- Total RAM accesses

***

### Round Robin
Round Robin is a scheduling algorithm in which each task/process is allocated a fixed amount of CPU time. Each task gets the same amount of CPU time. This fixed time is called quantum time. In this simulation, quantum time is equal to 3. 

#### Why Round Robin?
The benefits of this algorithm for this simulation are:
- Fairness: Every task gets a chance to execute.
- No Starvation: Long tasks cannot block shorter tasks indefinitely.
- Easy Visualization of Memory Blocks Movement: The rotation of tasks makes scheduler behavior clear in the cycle-by-cycle output and clearly showcases the movement of memory blocks in the cache hierarchy.

***

### Memory Access Behavior
Each task contains:
- Task ID
- Burst Time
- List of Memory Blocks (stored in a vector)

Example:
TASK T1 BURST 5 MEM M1 M4 M7

#### Execution Model
A task first processes its memory requests one by one. For every memory block, first search L1. Upon cache miss, search L2. If cache miss, search L3. Else, fetch from RAM if not found. If cache memory is found in L2, L3 or RAM, promote the memory block to L1. Evict oldest blocks from L1 to L2. If L2 is full, evict oldest block to L3. Hence the cache hierarchy is L1 -> L2 -> L3.

**After all memory requests for a task are completed, "CPU executes" is displayed for the remaining burst cycles.**

***

### Input Format
Example:  
TASK T1 BURST 5 MEM M1 M4 M7  
TASK T2 BURST 3 MEM M2 M1  

***

### Example Output
Cycle 1 running: T1 Requesting M1  
L1: [] >>MISS  
L2: [] >>MISS  
L3: [] >>MISS  
  
Fetching from RAM  
Promoting to L1  
  
L1: [M1]  
L2: []  
L3: []  
  
  
Cycle 2 running: T1 Requesting M4  
L1: [M1] >>MISS  
L2: [] >>MISS  
L3: [] >>MISS  
  
Fetching from RAM  
Promoting to L1  
  
L1: [M1,M4]  
L2: []  
L3: []  
  
  
Cycle 3 running: T1 Requesting M7  
L1: [M1,M4] >>MISS  
L2: [] >>MISS  
L3: [] >>MISS  
  
Fetching from RAM  
Promoting to L1  
  
L1: [M1,M4,M7]  
L2: []  
L3: []  

***

### Modules

#### main
Link between RoundRobin and CacheSystem. Starting point of execution

#### RoundRobin
Responsible for:
- Ready queue management
- Round Robin execution
- Task switching
- Cycle tracking

#### CacheSystem
Responsible for:
- Cache lookup
- Hit/Miss detection
- FIFO eviction
- RAM fetch tracking

#### Task
Stores:
- Task ID
- Burst time
- Remaining time
- Memory block list
- Current memory access position

***

### Compilation

Compile:

```g++ *.cpp -o simulator.exe```

Run:

```./simulator.exe```

