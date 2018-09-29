//
// Created by quintero on 9/22/18.
//

#include <fstream>
#include <iostream>
#include <sstream>
#include "InputImporter.h"
#include "Workstation.h"
#include "Task.h"

using namespace std;

void InputImporter::loadTasksAndWorkstations(string file_name, Task *tasks_array, Workstation *workstation_array, int & numTasks, int & numWorkstations) {

    // load the file
    //TODO: figure out filepath stuff
    ifstream inputFile;
    inputFile.open(file_name);

    if (inputFile.is_open()) {
        // read the number of tasks
        string entry;
        getline(inputFile, entry, ' ');
        numTasks = stoi(entry);

        // read the number of workstations
        getline(inputFile, entry, ' ');
        numWorkstations = stoi(entry);

        // make the arrays
        tasks_array = new Task[numTasks];
        workstation_array = new Workstation[numWorkstations];
        for (int i = 0; i < numWorkstations; i++) {
            Workstation ws = Workstation(i);
            workstation_array[i] = ws;
        }

        // load the tasks into the array
        for (int x = 0; x < numTasks; x++) {
            int * times = new int[numWorkstations];
            getline(inputFile, entry, ' ');
            int availTime = stoi(entry);

            for (int i = 0; i < numWorkstations; i++) {
                getline(inputFile, entry, ' ');
                times[i] = stoi(entry);
            }

            Task task = Task(x, availTime, times);
            tasks_array[x] = task;
        }

        inputFile.close();
    } else {
        cerr << "COULD NOT OPEN FILE" << endl;
    }
}