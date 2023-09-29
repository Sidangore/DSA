#include <iostream>
#include <iomanip>

int run_function_with_time_calculator(int arr[], int n, int x, int (*function) (int[], int, int)) {
    // To get the high precision execution time in s
    clock_t start, end;
    start = clock();

    // Call your function here
    int index = function(arr, n, x);

    // Ending the time of execution
    end = clock();

    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    std::cout << "Time taken by program = " << std::fixed << time_taken << std::setprecision(5) << "s" << std::endl;

    return index;
}

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