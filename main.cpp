#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>
#include "Task.h"
#include "Workstation.h"
#include "InputImporter.h"

using namespace std;

bool done(Workstation ws[], vector<Task> remainingTasks, int numTasks);
void selectNextTask(Workstation &workstation, Workstation ws[]);
void addToWorkstations(Task taskToAdd, Workstation ws[]);
bool checkForOverlap(int taskNumCheck, Workstation ws[]);

const int NUM_WORKSTATIONS = 3;
int currentTime = 0;

int main() {
    // the dynamically sized tasks array
    Task * taskArray = nullptr;
    Workstation * workstationArray = nullptr;
    int numTasks = 0;
    int numWorkstations = 0;

    // import the tasks(jobs)
    InputImporter::loadTasksAndWorkstations("../test_input.txt", taskArray, workstationArray, numTasks, numWorkstations);

    vector<Task> remainingTasks(taskArray, taskArray + numTasks);

    while(!done(workstationArray, remainingTasks, numTasks)) { //calls the done function below which will check if we are finished
        //Adds tasks that start at currentTime to the workstations' possibleTasks vectors
        for(int i = 0; i < remainingTasks.size(); i++) {
            if(remainingTasks.at(i).availableTime == currentTime) {
                addToWorkstations(remainingTasks.at(i), workstationArray);
                remainingTasks.erase(remainingTasks.begin() + i);
            }
        }

        for(int i = 0; i < NUM_WORKSTATIONS; i++) {
            if(workstationArray[i].cumulativeTime == currentTime) {
                selectNextTask(workstationArray[i], workstationArray);
            }
        }
        currentTime++;
    }

    int totalTime = 0;
    for(int i = 0; i < NUM_WORKSTATIONS; i++) {
        if(workstationArray[i].cumulativeTime > totalTime) {
            totalTime = workstationArray[i].cumulativeTime;
        }
    }

    ofstream outputFile;
    outputFile.open("output.txt");

    outputFile << totalTime << endl;

    for(int i = 0; i < numTasks; i++) {
        if(taskArray[i].taskNum == i) {
            outputFile << taskArray[i].print();
            if(i != numTasks - 1) {
                outputFile << endl;
            }
        } else {
            cout << "Something done f***ed up in the order of tasks" << endl;
        }
    }

    //TODO: verify our results

    delete[] workstationArray;
    delete[] taskArray;

    return 0;
}

void addToWorkstations(Task taskToAdd, Workstation *ws) {
    //Adds taskToAdd to the possibleTasks vectors in each of the n Workstations in ws[]
    for(int i = 0; i < NUM_WORKSTATIONS; i++) {
        ws[i].possibleTasks.push_back(taskToAdd);
    }
}

void selectNextTask(Workstation &workstation, Workstation *ws) {
    //Selects a new task for the supplied workstation using a shortest-time-first scheme
    bool foundTask = false;
    int minIndex = -1;
    int minTime = INT_MAX;
    for(int i = 0; i < workstation.possibleTasks.size(); i++) {
        if(workstation.possibleTasks.at(i).runTimes[workstation.wsNumber] < minTime && !checkForOverlap(workstation.possibleTasks.at(i).taskNum, ws)) {
            foundTask = true;
            minTime = workstation.possibleTasks.at(i).runTimes[workstation.wsNumber];
            minIndex = i;
        }
    }
    if(foundTask) {
        workstation.assignTask(workstation.possibleTasks.at(minIndex), minIndex);
    } else {
        workstation.currentTaskNum = NULL;
        workstation.cumulativeTime++;
    }
}

bool checkForOverlap(int taskNumCheck, Workstation *ws) {
    for(int i = 0; i < NUM_WORKSTATIONS; i++) {
        if(ws[i].currentTaskNum == taskNumCheck && ws[i].cumulativeTime > currentTime) {
            return true;
        }
    }
    return false;
}

bool done(Workstation *ws, vector<Task> remainingTasks, int numTasks) {
    //Determines if we have completed all of the tasks on all n of the Workstations in ws[]
    if(!remainingTasks.empty()) {
        return false;
    }
    for(int i = 0; i < NUM_WORKSTATIONS; i++) {
        if(!ws[i].possibleTasks.empty()) {
            return false;
        }
        if(ws[i].numTasksPerformed < numTasks) {
            return false;
        } else if(ws[i].numTasksPerformed > numTasks) {
            cout << "Something done f***ed up because you did more tasks than there were" << endl;
            return true;
        }
    }
    return true;
}