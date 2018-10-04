//
// Created by quintero on 9/22/18.
//

#include "Task.h"
#include <iostream>
#include <string>
#include <array>

using namespace std;

string Task::print() {
    return(to_string(callTimes[0]) + " " + to_string(callTimes[1]) + " " + to_string(callTimes[2]));
}

Task::Task() {
    runTimes = nullptr;
    callTimes = new long[3];
    taskNum = -1;
}

Task::Task(int taskNum, int availableTime, long * runTimes) {
    this->availableTime = availableTime;
    this->runTimes = runTimes;
    this->taskNum = taskNum;
    callTimes = new long[3];
}

Task::Task(int taskNum, int availableTime, long * runTimes, long * callTimes) {
    this->availableTime = availableTime;
    this->runTimes = runTimes;
    this->callTimes = callTimes;
    this->taskNum = taskNum;
}

/*Task::~Task() {
    delete[] runTimes;
    runTimes = NULL;
    delete[] callTimes;
    callTimes = NULL;
}
*/