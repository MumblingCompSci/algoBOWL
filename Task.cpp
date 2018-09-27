//
// Created by quintero on 9/22/18.
//

#include "Task.h"
string Task::print() {

}

Task::Task(int available_time, int * run_times) {
   this->available_time = available_time;
   this->run_times = run_times;

};

Task::~Task() {
    delete[](this->run_times);
    delete[](this->call_times);
}
