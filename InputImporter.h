//
// Created by quintero on 9/22/18.
//

#ifndef ALGOBOWL_INPUTIMPORTER_H
#define ALGOBOWL_INPUTIMPORTER_H

#include "Task.h"
#include "Workstation.h"
#include <string>

using namespace std;


class InputImporter {
public:
    static void loadTasksAndWorkstations(string file_name, Task *tasks_array, Workstation *workstation_array);
};


#endif //ALGOBOWL_INPUTIMPORTER_H
