//
// Created by quintero on 9/22/18.
//

#include <fstream>
#include <iostream>
#include <sstream>
#include "InputImporter.h"
#include "Workstation.h"

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

        // load the tasks into the array
        while (!inputFile.eof()) {
            int * times = new int[numWorkstations];
            for (int i = 0; i < numWorkstations; i++) {

            }
        }

        inputFile.close();
    } else {
        cerr << "COULD NOT OPEN FILE" << endl;
    }
}