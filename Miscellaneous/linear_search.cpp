#include <iostream>
#include <iomanip>
#include "running_time.h"

int linear_search(int arr[], int n, int x) {
    for(int i = 0; i < n; i++) {
        if (x == arr[i]) return i;
    }
    return -1;
}

int main() {

    int arr[] = {1, 3, 54, 7, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 2001; //TODO: paste from other program

    std::cout << x << " is found at " << run_function_with_time_calculator(arr, n, x, &linear_search) << std::endl;
    return 0;
}