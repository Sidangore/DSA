// Function to find the running time for execution of the function/ program/ algorithm.
#include <iostream>
#include <iomanip>

template <typename T, typename... Types>
T run_function_with_time_calculator(std::initializer_list<T> list, T (*function) (std::initializer_list<T> list)) {
    // To get the high precision execution time in s
    clock_t start, end;
    start = clock();

    // Call your function here
    function(list);

    // Ending the time of execution
    end = clock();

    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    std::cout << "Time taken by program = " << std::fixed << time_taken << std::setprecision(5) << "s" << std::endl;
}

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