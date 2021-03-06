//
// Created by dmachnik on 9/22/2018.
//

#include "Workstation.h"

Workstation::Workstation() {
    cumulativeTime = 0;
    numTasksPerformed = 0;
}

Workstation::Workstation(int wsNumber) {
    cumulativeTime = 0;
    this->wsNumber = wsNumber;
    numTasksPerformed = 0;
}

/*Workstation::~Workstation() {

}*/

void Workstation::assignTask(Task newTask, int index) {
    currentTaskNum = newTask.taskNum;
    newTask.callTimes[wsNumber] = cumulativeTime;
    cumulativeTime += newTask.runTimes[wsNumber];
    numTasksPerformed++;
    completedTasks.push_back(possibleTasks.at(index));
    possibleTasks.erase(possibleTasks.begin() + index);
}
