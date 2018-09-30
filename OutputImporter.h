//
// Created by Owner on 9/30/2018.
//

#ifndef ALGOBOWL_OUTPUTIMPORTER_H
#define ALGOBOWL_OUTPUTIMPORTER_H


#include "Task.h"
#include "Workstation.h"
#include <string>
#include <vector>

using namespace std;


class OutputImporter {
public:
    static int loadTasksAndWorkstations(string inFile_name, string outFile_name, vector<Task> &tasks_vector, int & numTasks, int & numWorkstations);
};

#endif //ALGOBOWL_OUTPUTIMPORTER_H


