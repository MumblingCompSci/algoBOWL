//
// Created by quintero on 9/22/18.
//

#ifndef ALGOBOWL_TASK_H
#define ALGOBOWL_TASK_H

#include <string>
using namespace std;

class Task {
public:
    long * runTimes;
    long * callTimes;
    int availableTime;
    int taskNum;

    string print();

    Task();
    Task(int taskNum, int available_time, long * run_times);
    Task(int taskNum, int available_time, long * run_times, long * callTimes);
    //~Task();
};


#endif //ALGOBOWL_TASK_H
