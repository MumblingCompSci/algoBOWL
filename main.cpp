#include <iostream>
#include <cmath>
#include <vector>
#include "Task.h"
#include "Workstation.h"
#include "InputImporter.h"

using namespace std;

bool done(Workstation ws[], int n);
void selectNextTask(Workstation &workstation);
void addToWorkstations(Task taskToAdd, Workstation ws[], int n);

int main() {
    const int NUM_WORKSTATIONS = 3;
    int currentTime = 0;

    // the dynamically sized tasks array
    Task * taskArray = nullptr;

    // import the tasks(jobs)
    //TODO: replace file string with something that makes more sense
    InputImporter::loadTasks("file string", taskArray);
    const int NUM_TASKS = 6;

    vector<Task> remainingTasks(taskArray, taskArray + NUM_TASKS);

    Workstation * workstationArray;
    Workstation workstation0(0);
    Workstation workstation1(1);
    Workstation workstation2(2);
    workstationArray[0] = workstation0;
    workstationArray[1] = workstation1;
    workstationArray[2] = workstation2;

    while(!done(workstationArray, NUM_WORKSTATIONS)) { //calls the done function below which will check if we are finished
        //Adds tasks that start at currentTime to the workstations' possibleTasks vectors
        for(int i = 0; i < remainingTasks.size(); i++) {
            if(remainingTasks.at(i).availableTime == currentTime) {
                addToWorkstations(remainingTasks.at(i), workstationArray, NUM_WORKSTATIONS);
                remainingTasks.erase(remainingTasks.begin() + i);
            }
        }

        for(int i = 0; i < NUM_WORKSTATIONS; i++) {
            if(workstationArray[i].cumulativeTime == currentTime) {
                selectNextTask(workstationArray[i]);
            }
        }
        currentTime++;
    }

    delete[] workstationArray;

    return 0;
}

void addToWorkstations(Task taskToAdd, Workstation *ws, int n) {
    //Adds taskToAdd to the possibleTasks vectors in each of the n Workstations in ws[]
    for(int i = 0; i < n; i++) {
        ws[i].possibleTasks.push_back(taskToAdd);
    }
}

void selectNextTask(Workstation &workstation) {
    //Selects a new task for the supplied workstation using a shortest-time-first scheme
    //TODO: write the selection for a smallest scheme
}

bool done(Workstation *ws, int n) {
    //Determines if we have completed all of the tasks on all n of the Workstations in ws[]
    return false;
}