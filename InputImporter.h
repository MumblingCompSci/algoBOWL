//
// Created by quintero on 9/22/18.
//

#ifndef ALGOBOWL_INPUTIMPORTER_H
#define ALGOBOWL_INPUTIMPORTER_H

#include "Task.h"
#include "Workstation.h"
#include <string>
#include <vector>

using namespace std;


class InputImporter {
public:
    static void generateInput(int n, string file);
    static void loadTasksAndWorkstations(string file_name, vector<Task> &tasks_vector, int & numTasks, int & numWorkstations);
};


#endif //ALGOBOWL_INPUTIMPORTER_H