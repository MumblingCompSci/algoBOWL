#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>
#include <ctime>
#include "Task.h"
#include "Workstation.h"
#include "InputImporter.h"
#include "OutputImporter.h"

using namespace std;

bool done(Workstation ws[], vector<Task> remainingTasks);
bool done(Workstation ws[]);
void selectNextTask(Workstation &workstation, Workstation ws[]);
bool verifierNextTask(Workstation &workstation, Workstation ws[]);
void addToWorkstations(Task taskToAdd, Workstation ws[]);
bool checkForOverlap(int taskNumCheck, Workstation ws[]);

const int NUM_WORKSTATIONS = 3;
long currentTime = 0;

const string randomInputFileName = "../randomInput.txt";

const string generateInputFileName = "../randomInput.txt";
const string generateOutputFileName = "../randomOutput.txt";

const string verifyInputFileName = "../randomInput.txt";
const string verifyOutputFileName = "../randomOutput.txt";

int main() {
    char userKey;

    cout << "Create an input (I), Generate an output (G) or Verify and output (V)?  ";
    cin >> userKey;

    if(userKey == 'I') {
        int n;
        cout << "How many tasks?";
        cin >> n;

        clock_t start = clock();

        InputImporter::generateInput(n, randomInputFileName);

        cout << "Generating random input..." << endl;
        cout << "Random input file: " << generateInputFileName << endl;

        clock_t end = clock();

        cout << "Random input file generated in " << ((double)(end - start))/CLOCKS_PER_SEC << " seconds." << endl;
    }

    else if (userKey == 'G') {
        //print some useful info (to make sure we're doing the right thing)
        cout << "Generating output..." << endl;
        cout << "Input file: " << generateInputFileName << endl;
        cout << "Output file: " << generateOutputFileName << endl;

        clock_t start = clock();

        // the dynamically sized tasks array
        vector<Task> taskVector;
        int numTasks = 0;
        int numWorkstations = 0;

        // import the tasks(jobs)
        InputImporter::loadTasksAndWorkstations(generateInputFileName, taskVector, numTasks, numWorkstations);

        vector<Task> remainingTasks = taskVector;

        Workstation * workstationArray = new Workstation[3];
        for (int i = 0; i < 3; i++) {
            Workstation ws(i);
            workstationArray[i] = ws;
        }

        while(!done(workstationArray, remainingTasks)) { //calls the done function below which will check if we are finished
            //Adds tasks that start at currentTime to the workstations' possibleTasks vectors
            for(int i = 0; i < remainingTasks.size(); i++) {
                if(remainingTasks.at(i).availableTime == currentTime) {
                    addToWorkstations(remainingTasks.at(i), workstationArray);
                    remainingTasks.erase(remainingTasks.begin() + i);
                    i--;
                }
            }

            for(int i = 0; i < NUM_WORKSTATIONS; i++) {
                if(workstationArray[i].cumulativeTime == currentTime) {
                    selectNextTask(workstationArray[i], workstationArray);
                }
            }
            currentTime++;
        }

        long totalTime = 0;
        for(int i = 0; i < NUM_WORKSTATIONS; i++) {
            if(workstationArray[i].cumulativeTime > totalTime) {
                totalTime = workstationArray[i].cumulativeTime;
            }
        }

        ofstream outputFile;
        outputFile.open(generateOutputFileName);

        if(outputFile.is_open()) {
            outputFile << totalTime << endl;

            for(int i = 0; i < numTasks; i++) {
                if(taskVector.at(i).taskNum == i) {
                    outputFile << taskVector.at(i).print();
                    if(i != numTasks - 1) {
                        outputFile << endl;
                    }
                } else {
                    cout << "Something done f***ed up in the order of tasks" << endl;
                }
            }
        } else {
            cerr << "COULD NOT OPEN FILE" << endl;
        }

        outputFile.close();

        delete[] workstationArray;

        clock_t end = clock();

        cout << "Output generated in " << ((double)(end - start))/CLOCKS_PER_SEC << " seconds." << endl;
    }

    else if (userKey == 'V') {
        //print some useful info (to make sure we're doing the right thing)
        cout << "Verifying output..." << endl;
        cout << "Input file: " << verifyInputFileName << endl;
        cout << "Output file: " << verifyOutputFileName << endl;

        clock_t start = clock();

        int calcTotalTime = 0;
        // the dynamically sized tasks array
        vector<Task> taskVector;
        int numTasks = 0;
        int numWorkstations = 0;

        // import the tasks(jobs)
        int givenTotalTime = OutputImporter::loadTasksAndWorkstations(verifyInputFileName, verifyOutputFileName,taskVector, numTasks, numWorkstations);

        Workstation * workstationArray = new Workstation[3];
        for (int i = 0; i < 3; i++) {
            Workstation ws(i);
            workstationArray[i] = ws;
            workstationArray[i].possibleTasks = taskVector;
        }

        while(!done(workstationArray) && givenTotalTime > currentTime) { //calls the done function below which will check if we are finished
            for(int i = 0; i < NUM_WORKSTATIONS; i++) {
                if(workstationArray[i].cumulativeTime == currentTime) {
                    bool overlap = !verifierNextTask(workstationArray[i], workstationArray);
                    // check for overlap
                    if(overlap){
                        cout << "Output incorrect: overlap on tasks";
                        return 0;
                    }
                }
            }
            currentTime++;
        }

        //check that no tasks were skipped
        if(!workstationArray[0].possibleTasks.empty() || !workstationArray[1].possibleTasks.empty() || !workstationArray[2].possibleTasks.empty()) {
            cout << "Output incorrect: a task has not been executed";
            return 0;
        }

        //double-check for above: check that all stations have completed all tasks
        for(int i = 0; i < NUM_WORKSTATIONS; i++) {
            if(workstationArray[i].numTasksPerformed != taskVector.size()) {
                cout << "Output incorrect: missing tasks from completion";
                return 0;
            }
        }

        //find the largest internal time to compare w/ given time
        for(int i = 0; i < NUM_WORKSTATIONS; i++) {
            if(workstationArray[i].cumulativeTime > calcTotalTime) {
                calcTotalTime = workstationArray[i].cumulativeTime;
            }
        }

        //check if the calculated total time was less than the output file said
        if(givenTotalTime < calcTotalTime){
            cout << "Output incorrect: given total time too small";
            return 0;
        }

        //check if the calculated total was greater than their output file said
        if (givenTotalTime > calcTotalTime) {
            cout << "Output incorrect: given total time too large";
            return 0;
        }

        cout << "IT DID IT!!!!!" << endl;

        clock_t end = clock();

        cout << "Output verified in " << ((double)(end - start))/CLOCKS_PER_SEC << " seconds." << endl;
    }

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
        //cout << "Assigning task " << workstation.possibleTasks.at(minIndex).taskNum << " to Workstation " << workstation.wsNumber << " at time " << currentTime << endl;
        workstation.assignTask(workstation.possibleTasks.at(minIndex), minIndex);
    } else {
        workstation.currentTaskNum = -1;
        workstation.cumulativeTime++;
        //cout << "No task assigned to Workstation " << workstation.wsNumber << " at time " << currentTime << endl;
    }
}

bool verifierNextTask(Workstation &workstation, Workstation *ws) {
    //Selects a new task for the supplied workstation using a shortest-time-first scheme
    bool foundTask = false;
    int index = 0;
    for(int i = 0; i < workstation.possibleTasks.size(); i++) {
        if(workstation.possibleTasks.at(i).callTimes[workstation.wsNumber] == currentTime && !checkForOverlap(workstation.possibleTasks.at(i).taskNum, ws)) {
            foundTask = true;
            index = i;
            break;
        }
        else if(workstation.possibleTasks.at(i).callTimes[workstation.wsNumber] == currentTime && checkForOverlap(workstation.possibleTasks.at(i).taskNum, ws)){
            return false;
        }
    }
    if(foundTask) {
        workstation.assignTask(workstation.possibleTasks.at(index), index);
    } else {
        workstation.currentTaskNum = -1;
        workstation.cumulativeTime++;
    }
    return true;
}

bool checkForOverlap(int taskNumCheck, Workstation *ws) {
    for(int i = 0; i < NUM_WORKSTATIONS; i++) {
        if(ws[i].currentTaskNum == taskNumCheck && ws[i].cumulativeTime > currentTime) {
            //cout << endl << "Task number " << taskNumCheck << " is overlapping with workstation " << i << " at time " << currentTime << endl;
            return true;
        }
    }
    return false;
}

bool done(Workstation *ws, vector<Task> remainingTasks) {
    //Determines if we have completed all of the tasks on all n of the Workstations in ws[]
    if(!remainingTasks.empty()) {
        return false;
    }
    for(int i = 0; i < NUM_WORKSTATIONS; i++) {
        if(!ws[i].possibleTasks.empty()) {
            return false;
        }
    }
    return true;
}

bool done(Workstation *ws) {
    for(int i = 0; i < NUM_WORKSTATIONS; i++) {
        if(!ws[i].possibleTasks.empty()) {
            return false;
        }
    }
    return true;
}