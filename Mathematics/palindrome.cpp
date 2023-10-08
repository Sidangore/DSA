#include <iostream>
#include <iomanip>

// void run_function_with_time_calculator(int arr[], int n, int (*function) (int[], int)) {
//     // To get the high precision execution time in s
//     clock_t start, end;
//     start = clock();

//     // Call your function here
//     int sum = function(arr, n);

//     // Ending the time of execution
//     end = clock();

//     std::cout << "SUM = " << sum << std::endl;
//     double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
//     std::cout << "Time taken by program = " << std::fixed << time_taken << std::setprecision(5) << "s" << std::endl;
// }

bool is_palindrome(int n) {
    int m = n, rev = 0;
    while (m != 0) {
        rev = (rev * 10) + (m % 10);
        m /= 10;
    }
    return (rev == n);
}

int main() {
    // Start writing your code below...
    int num;
    std::cout << "Enter a number: ";
    std::cin >> num;

    std::cout << is_palindrome(num) << std::endl;

    return 0;
}