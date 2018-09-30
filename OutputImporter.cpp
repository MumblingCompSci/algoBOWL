//
// Created by Owner on 9/30/2018.
//

#include <fstream>
#include <iostream>
#include <sstream>
#include <array>
#include <vector>
#include "OutputImporter.h"
#include "Workstation.h"
#include "Task.h"

using namespace std;

int OutputImporter::loadTasksAndWorkstations(string inFile_name, string outFile_name, vector<Task> &tasks_vector, int & numTasks, int & numWorkstations) {

    // load the input file
    ifstream inputFile;
    inputFile.open(inFile_name);

    // load the output file
    ifstream outputFile;
    outputFile.open(outFile_name);

    int givenTotalTime;
    if (inputFile.is_open() && outputFile.is_open()) {
        // read the number of tasks
        string entry;
        getline(inputFile, entry, ' ');
        numTasks = stoi(entry);

        // read the number of workstations
        getline(inputFile, entry);
        numWorkstations = stoi(entry);

        // read the given total time
        getline(outputFile, entry);
        givenTotalTime = stoi(entry);

        // load the tasks into the array
        for (int x = 0; x < numTasks; x++) {
            int * runTimes = new int[3];
            getline(inputFile, entry, ' ');
            int availTime = stoi(entry);

            for (int i = 0; i < numWorkstations - 1; i++) {
                getline(inputFile, entry, ' ');
                runTimes[i] = stoi(entry);
            }
            getline(inputFile, entry);
            runTimes[2] = stoi(entry);

            int * callTimes = new int[3];

            // call times
            for (int i = 0; i < numWorkstations - 1; i++) {
                getline(outputFile, entry, ' ');
                callTimes[i] = stoi(entry);
            }
            getline(outputFile, entry);
            callTimes[2] = stoi(entry);

            Task task = Task(x, availTime, runTimes, callTimes);
            tasks_vector.push_back(task);
        }

        inputFile.close();
        outputFile.close();
    } else {
        cerr << "COULD NOT OPEN FILE" << endl;
    }

    return givenTotalTime;
}
