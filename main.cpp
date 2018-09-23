#include <iostream>
#include "Task.h"
#include "Workstation.h"
#include "InputImporter.h"

using namespace std;

int main() {
    int current_time = 0;

    // the dynamically sized tasks array
    Task * task_array = nullptr;

    // import the tasks(jobs)
    //TODO: replace file string with something that makes more sense
    InputImporter::loadTasks("file string", task_array);


    /* TODO: The Solutions...
     * 1. smallest/largest scheme
     * 2. balanced scheme
     * 3. random scheme
     * ....
     *
     */

    return 0;
}