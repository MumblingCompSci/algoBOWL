#include <iostream>
#include <cmath>
#include "Task.h"
#include "Workstation.h"
#include "InputImporter.h"

using namespace std;

bool done(Workstation ws[], int n);
void selectNextTask(Workstation &workstation);

int main() {
    int current_time = 0;

    // the dynamically sized tasks array
    Task * task_array = nullptr;
    int num_workstations = 3;

    // import the tasks(jobs)
    //TODO: replace file string with something that makes more sense
    InputImporter::loadTasks("file string", task_array);



    Workstation * workstationArray;
    Workstation workstation0(0);
    Workstation workstation1(1);
    Workstation workstation2(2);
    workstationArray[0] = workstation0;
    workstationArray[1] = workstation1;
    workstationArray[2] = workstation2;

    while(!done(workstationArray, num_workstations)) { //calls the done function below which will check if we are finished
        //TODO: Add tasks that start at current_time to the workstations' possibleTasks arrays
        for(int i = 0; i < num_workstations; i++) {
            if(workstationArray[i].cumulativeTime == current_time) {
                selectNextTask(workstationArray[i]);
            }
        }
        current_time++;
    }

    delete[] workstationArray;

    return 0;
}

void selectNextTask(Workstation &workstation) {
    //TODO: write the selection for a smallest scheme
}

bool done(Workstation *ws, int n) {
    return false;
}