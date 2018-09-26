//
// Created by quintero on 9/22/18.
//

#ifndef ALGOBOWL_INPUTIMPORTER_H
#define ALGOBOWL_INPUTIMPORTER_H

#include "Task.h"
#include <string>

using namespace std;


class InputImporter {
public:
    static void loadTasks(string file_name, Task * tasks_array);
};


#endif //ALGOBOWL_INPUTIMPORTER_H