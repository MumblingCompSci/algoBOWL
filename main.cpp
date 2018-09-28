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
    Task * taskArray = nullptr;
    Workstation * workstationArray = nullptr;
    int numTasks = 0;
    int numWorkstations = 0;

    // import the tasks(jobs)
    //TODO: replace file string with something that makes more sense
    InputImporter::loadTasksAndWorkstations("file string", taskArray, workstationArray, numTasks, numWorkstations);

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

    delete[] workstationArray;
    delete[] taskArray;

    return 0;
}

void selectNextTask(Workstation &workstation) {
    //TODO: write the selection for a smallest scheme
}

bool done(Workstation *ws, int n) {
    return false;
}