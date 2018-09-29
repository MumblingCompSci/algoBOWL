//
// Created by dmachnik on 9/22/2018.
//

#include "Workstation.h"

Workstation::Workstation() {
    cumulativeTime = 0;
    currentTaskNum = -1;
    wsNumber = -1;
    numTasksPerformed = 0;
}

Workstation::Workstation(int wsNumber) {
    cumulativeTime = 0;
    currentTaskNum = -1;
    this->wsNumber = wsNumber;
    numTasksPerformed = 0;
}

void Workstation::assignTask(Task newTask) {
    currentTaskNum = newTask.taskNum;
    newTask.callTimes[wsNumber] = cumulativeTime;
    cumulativeTime += newTask.runTimes[wsNumber];
    numTasksPerformed++;
}
