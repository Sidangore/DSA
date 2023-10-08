#include <iostream>
#include <iomanip>

void run_function_with_time_calculator(int arr[], int n, int (*function) (int[], int)) {
    // To get the high precision execution time in s
    clock_t start, end;
    start = clock();

    // Call your function here
    int sum = function(arr, n);

    // Ending the time of execution
    end = clock();

    std::cout << "SUM = " << sum << std::endl;
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    std::cout << "Time taken by program = " << std::fixed << time_taken << std::setprecision(5) << "s" << std::endl;
}

int main() {
    // Start writing your code below...
    int num, res = 0;
    std::cout << "Enter a digit: "; 
    std::cin >> num;

    clock_t start, end;
    start = clock();

    while (num > 0) {
        num /= 10;
        res++;
    }

    end = clock();

    std::cout << "Digits = " << res << std::endl; 
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    std::cout << "Time taken by program = " << std::fixed << time_taken << std::setprecision(5) << "s" << std::endl;

    return 0;
} 