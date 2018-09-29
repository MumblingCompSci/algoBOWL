//
// Created by quintero on 9/22/18.
//

#ifndef ALGOBOWL_TASK_H
#define ALGOBOWL_TASK_H

#include <string>
using namespace std;

class Task {
public:
    int * runTimes;
    int * callTimes;
    int availableTime;
    int taskNum;

    string print();

    Task();
    Task(int taskNum, int available_time, int * run_times);
    ~Task();
};


#endif //ALGOBOWL_TASK_H
