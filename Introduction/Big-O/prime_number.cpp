#include <iostream>
#include <iomanip>

void run_function_with_time_calculator(void (*function) ()) {
    // To get the high precision execution time in s
    clock_t start, end;
    start = clock();

    // Call your function here
    function();

    // Ending the time of execution
    end = clock();

    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    std::cout << "Time taken by program = " << std::fixed << time_taken << std::setprecision(5) << "s" << std::endl;
}

bool check_prime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i <= n/2; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

void call_primes() {
    for (int i = 0; i < 101; i++) {
        std::cout << check_prime(i) << " ";
    }
    std::cout << std::endl;
}

int main() {
    // Start writing your code below...
    run_function_with_time_calculator(&call_primes);
    return 0;
}