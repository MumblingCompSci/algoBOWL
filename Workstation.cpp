//
// Created by dmachnik on 9/22/2018.
//

#include "Workstation.h"

Workstation::Workstation() {
    cumulativeTime = 0;
    numTasksPerformed = 0;
    wsNumber = -1;
}

Workstation::Workstation(int wsNumber) {
    cumulativeTime = 0;
    numTasksPerformed = 0;
    this->wsNumber = wsNumber;
}

void Workstation::assignTask(Task newTask) {

}
