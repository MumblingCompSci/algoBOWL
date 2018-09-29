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
    Workstation * workstationArray = nullptr;
    int numTasks = 0;
    int numWorkstations = 0;

    // import the tasks(jobs)
    //TODO: replace file string with something that makes more sense
    InputImporter::loadTasksAndWorkstations("../test_input.txt", taskArray, workstationArray, numTasks, numWorkstations);

    vector<Task> remainingTasks(taskArray, taskArray + numTasks);

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

    //TODO: write results out to a file

    delete[] workstationArray;
    delete[] taskArray;

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