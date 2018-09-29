//
// Created by dmachnik on 9/22/2018.
//

#ifndef ALGOBOWL_WORKSTATION_H
#define ALGOBOWL_WORKSTATION_H
#include "Task.h"

#include <vector>


using namespace std;

class Workstation {
public:
    int cumulativeTime;
    int currentTaskNum;
    int wsNumber;
    int numTasksPerformed;
    vector<Task> possibleTasks;
    vector<Task> completedTasks;

    Workstation();

    Workstation(int wsNumber);

    void assignTask(Task newTask, int index);

};

#endif //ALGOBOWL_WORKSTATION_H