//
// Created by quintero on 9/22/18.
//

#ifndef ALGOBOWL_TASK_H
#define ALGOBOWL_TASK_H

#include <string>
using namespace std;

class Task {
public:
    int * run_times;
    int * call_times;
    int available_time;

    string print();

    Task(int available_time, int run_times[]);
    ~Task();
};


#endif //ALGOBOWL_TASK_H
