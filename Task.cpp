//
// Created by quintero on 9/22/18.
//

#include "Task.h"
#include <iostream>
#include <string>

using namespace std;

string Task::print() {
    cout << runTimes[0] << ' ' << runTimes[1] << ' ' << runTimes[2] << endl;
    return(to_string(runTimes[0]) + " " + to_string(runTimes[1]) + " " + to_string(runTimes[2]));
}

Task::Task() {
    availableTime = -1;
    runTimes = nullptr;
    taskNum = -1;
}

Task::Task(int taskNum, int availableTime, int * runTimes) {
    this->availableTime = availableTime;
    this->runTimes = runTimes;
    this->taskNum = taskNum;
}

Task::~Task() {
    delete[](this->runTimes);
    delete[](this->callTimes);
}
