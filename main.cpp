#include <iostream>
#include "Task.h"
#include "Workstation.h"
#include "InputImporter.h"

using namespace std;

int main() {
    int current_time = 0;

    // the dynamically sized tasks array
    Task * task_array = nullptr;
    Workstation * workstation_array = nullptr;

    // import the tasks(jobs)
    //TODO: replace file string with something that makes more sense
    InputImporter::loadTasksAndWorkstations("file string", task_array, workstation_array);


    /* TODO: The Solutions...
     * 1. smallest/largest scheme
     * 2. balanced scheme
     * 3. random scheme
     * ....
     *
     */

    delete[] workstation_array;
    delete[] task_array;

    return 0;
}