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

void InputImporter::loadTasksAndWorkstations(string file_name, vector<Task> &tasks_vector, int & numTasks, int & numWorkstations) {

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
        getline(inputFile, entry);
        numWorkstations = stoi(entry);

        // load the tasks into the array
        for (int x = 0; x < numTasks; x++) {
            int * times = new int[3];
            getline(inputFile, entry, ' ');
            int availTime = stoi(entry);
            //cout << "Available time: " << availTime << endl << "Times: ";

            for (int i = 0; i < numWorkstations - 1; i++) {
                getline(inputFile, entry, ' ');
                times[i] = stoi(entry);
                //cout << times[i] << ' ';
            }
            getline(inputFile, entry);
            times[2] = stoi(entry);
            //cout << times[2] << endl;

            Task task = Task(x, availTime, times);
            tasks_vector.push_back(task);
        }

        inputFile.close();
    } else {
        cerr << "COULD NOT OPEN FILE" << endl;
    }
}