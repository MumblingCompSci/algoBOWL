#include <iostream>
#include <cmath>
#include "Task.h"
#include "Workstation.h"
#include "InputImporter.h"

using namespace std;

bool done(Workstation ws[], int n);
void selectSmallestScheme(Workstation &workstation, Task *task_array);
void selectBalancedScheme(Workstation *ws, Task *task_array, int ws_num, int num_workstations);
void selectRandomScheme(Workstation &workstation, Task *task_array);

int main() {
    int current_time = 0;

    // the dynamically sized tasks array
    Task * task_array = nullptr;
    int num_workstations = 3;

    // import the tasks(jobs)
    //TODO: replace file string with something that makes more sense
    InputImporter::loadTasks("file string", task_array);


    /* TODO: The Solutions...
     * 1. smallest/largest scheme
     * 2. balanced scheme
     * 3. random scheme
     * ....
     *
     */

    auto * workstation_array = new Workstation[num_workstations];
    Workstation ws0, ws1, ws2;
    workstation_array[0] = ws0;
    workstation_array[1] = ws1;
    workstation_array[2] = ws2;

    while(!done(workstation_array, num_workstations)) {
        for(int i = 0; i < num_workstations; i++) {
            if(workstation_array[i].cumulative_time == current_time) {
                selectSmallestScheme(workstation_array[i], task_array);
                selectBalancedScheme(workstation_array, task_array, i, num_workstations);
                selectRandomScheme(workstation_array[i], task_array);
            }
        }
        current_time++;
    }

    delete[] workstation_array;

    return 0;
}

void selectSmallestScheme(Workstation &workstation, Task *task_array) {
    //TODO: write the selection for a smallest/largest scheme
}

void selectBalancedScheme(Workstation *ws, Task *task_array, int ws_num, int num_workstations) {
    //TODO: write the selection for a balanced scheme
    int balanceGoal;
    if(ws_num != num_workstations - 1) {
        balanceGoal = ws[ws_num + 1].cumulative_time;
    } else {
        balanceGoal = ws[0].cumulative_time;
    }

    //I need to get this working

    /*
    int difference = -1;
    Task * choice = new Task;
    for(auto t : task_array) {
        if(difference == -1 || (t.run_times[ws_num] > 0 && abs((ws[ws_num].cumulative_time + t.run_times[ws_num]) - balanceGoal) < difference)) {
            difference = abs((ws[ws_num].cumulative_time + t.run_times[ws_num]) - balanceGoal);
            choice = t;
        }
    }

    ws[ws_num].getTask(choice);
    */
}

void selectRandomScheme(Workstation &workstation, Task *task_array) {
    //TODO: write the selection for a random scheme
}

bool done(Workstation *ws, int n) {
    for(int i = 0; i < n; i++) {
        if(!ws[i].done) {
            return false;
        }
    }
    return true;
}