//
// Created by dmachnik on 9/22/2018.
//

#ifndef ALGOBOWL_WORKSTATION_H
#define ALGOBOWL_WORKSTATION_H
#include "Task.h";

using namespace std;

class Workstation {
public:
    int cumulative_time = 0;

    Workstation();
    ~Workstation();
    void getTask(Task newTask);
};


#endif //ALGOBOWL_WORKSTATION_H
