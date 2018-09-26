//
// Created by quintero on 9/22/18.
//

#include "Task.h"
#include <iostream>

using namespace std;

void Task::print() {
    cout << runTimes[0] << ' ' << runTimes[1] << ' ' << runTimes[2] << endl;
}

Task::Task(int availableTime, int * runTimes) {
    this->availableTime = availableTime;
    this->runTimes = runTimes;

};

Task::~Task() {
    delete[](this->run_times);
    delete[](this->call_times);
}
