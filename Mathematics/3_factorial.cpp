#include <iostream>
#include <iomanip>

void run_function_with_time_calculator(int n, int (*function) (int)) {
    // To get the high precision execution time in s
    clock_t start, end;
    start = clock();

    // Call your function here
    int res = function(n);

    // Ending the time of execution
    end = clock();

    std::cout << "Factorial = " << res << std::endl;
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    std::cout << "Time taken by program = " << std::fixed << time_taken << std::setprecision(5) << "s" << std::endl;
}

int fact_itr(int n) {
    int res = 1;
    while (n >= 2) {
        res *= n;
        n--;
    }
    return res;
}

int fact_rec(int n) {
    if (n == 0) return 1;
    return n * fact_rec(n - 1);
}

int main() {
    // Start writing your code below...

    int n;
    std::cin >> n;
    
    run_function_with_time_calculator(n, fact_rec);
    
    return 0;
}