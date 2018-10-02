//
// Created by quintero on 9/22/18.
//

#include <fstream>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include "InputImporter.h"
#include "Workstation.h"
#include "Task.h"

using namespace std;

void InputImporter::generateInput(int n, string file) {
    ofstream out; //declare file out stream
    out.open(file);

    out << n << ' ' << 3 << endl; //insert the number of tasks and number of workstations

    srand(time(0));

    for(int i = 0; i < n; i++) { //create n-1 tasks
        int startTime, runTime1, runTime2, runTime3;
        startTime = rand() % 51; //will result in start times between 0 and 50
        runTime1 = (rand() % 50) + 1; //will result in a run time between 1 and 50
        runTime2 = (rand() % 50) + 1;
        runTime3 = (rand() % 50) + 1;

        out << startTime << ' ' << runTime1 << ' ' << runTime2 << ' ' << runTime3;

        if(i != n - 1) {
            out << endl;
        }
    }

    out.close();
}

void InputImporter::loadTasksAndWorkstations(string file_name, vector<Task> &tasks_vector, int & numTasks, int & numWorkstations) {

    // load the file
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