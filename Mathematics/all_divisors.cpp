#include <iostream>
#include <iomanip>

void run_function_with_time_calculator(int n, void (*function) (int)) {
    // To get the high precision execution time in s
    clock_t start, end;
    start = clock();

    // Call your function here
    function(n);

    // Ending the time of execution
    end = clock();

    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    std::cout << "Time taken by program = " << std::fixed << time_taken << std::setprecision(5) << "s" << std::endl;
}
/**
 * Naive solution
 * 
 * We check from 1 to n,
 * if n % i == 0 => it is a divisor, hence we print.
 * 
 * Time Complexity = Θ(n)
 * Auxilary Space = Θ(1)
*/
void all_div_1(int n) {
    for(int i = 1; i <=n; i++) {
        if(n % i == 0) std::cout << i << ", ";
    }
    std::cout << std::endl;
}

/**
 * The efficient solution
 * 
 * As, one of the divisors of the number n, 
 * would lie before the √n.
 * 
 * For ex. 
 * if, x * y ≤ n (here, x & y are divisor pair of n)
 * &, x ≤ y
 * => x * x ≤ n
 * => x ≤ √n
 * 
 * Hence, one divisor will be on or before √n.
 * 
 * Here, the Time complexity would be O(√n)
 * and Auxiliary space = O(1)
*/
void all_div_2(int n) {
    for(int i = 1; (i * i) <= n; i++) {
        if((n % i) == 0) {
            std::cout << i << ", ";
            if(i != n/i) std::cout << (n / i) << ", ";
        }
    }
    std::cout << std::endl;
}

/**
 * More efficient solution
 * 
 * Here, we first print the divisors which come before < √n, from 1 
 * => 1 ≤ x < √n
 * The, we print the counterpart of the above divisors from √n to n 
 * => √n ≤ x ≤ n
 * 
 * This can be done using 2 for loops, 
 * First, one to print from 1 till √n
 * Second from decreasing the i value and printing the counterpart as n/i.
 * 
 * This will give divisors in incrementing order.
 * 
 * Time Complexity = Θ(√n)
 * Auxiliary Space = Θ(1)
*/
void all_div_3(int n) {
    int i;
    for(i = 1; i*i < n; i++){
        if(n % i == 0) std::cout << i << ", ";
    }
    for(; i >= 1; i--) {
        if(n % i == 0) std::cout << n/i << ", ";
    }
    std::cout << std::endl;
}

int main() {
    // Start writing your code below...
    int n;
    std::cout << "Number = ";
    std::cin >> n;

    run_function_with_time_calculator(n, all_div_3);

    return 0;
}