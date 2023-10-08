#include <iostream>
#include <iomanip>
#include <sys/stat.h>
#include <sys/types.h>


int main() {
    // Start writing your code below...
    std::string months[] = {"JAN", "FEB", "MAR", "APR", "MAY", "JUN", "JUL", "AUG", "SEP", "OCT", "NOV", "DEC"};
    std::string year = "2023";
    std::string base_loc = "/Users/siddhant.angore/Desktop/Test/";

    //writing loop to create the months
    for (std::string month: months) {
        std::string folder_name = base_loc + month + " " + year;
        if (mkdir(folder_name.data(), 0777) == -1) {
            std::cerr << "error: " << strerror(errno) << std::endl;
        }
    }

    return 0;
}