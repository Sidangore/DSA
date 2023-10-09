/**
 * Computing powers
*/

#include <iostream>
#include <iomanip>

void run_function_with_time_calculator(int n, int x, int (*function) (int, int)) {
    // To get the high precision execution time in s
    clock_t start, end;
    start = clock();

    // Call your function here
    std::cout << function(n, x) << std::endl;

    // Ending the time of execution
    end = clock();

    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    std::cout << "Time taken by program = " << std::fixed << time_taken << std::setprecision(5) << "s" << std::endl;

}
/**
 * Naive solution
 * 
 * Time Complexity = Θ(n)
*/
int power_1(int x, int n) {
    if( x == 0) return 0;
    else if (n == 0 || x == 1) return 1;
    else if (n == 1) {
        return x;
    } 
    int res = x;
    for(int i = 2; i <= n; i++) {
        res *= x;
    }

    // int res = 1;
    // for(int i = 0; i < n; i++) {
    //     res = res*x;
    // }

    return res;
}

/**
 * The efficient solution - Iterative
 * 
 * We use binary exponentiation
 * 
 * Every number can be written as a sum of power of 2
 * 
 * We can traverse through all bits of a number from LSB to MSB (Least Significant Bit) (Most Significant Bit)
 * 
 * Time complexity = O(logn)
 * As, it takes logn time to traverse through the bits of n
 * Auxiliary space = O(1)
 * 
 * In x^n, we in every bits of n,
 * Consider the corresponding bit 1, as a multiplier of x raise to the power
 * 
 * To optimise it further,
 * if(n % 2 != 0) res = res * x;
 * => ... (n & 1)...
 * 
 * &, n = n/2;
 * => n = n>>1;
 * 
*/ 
int power_2(int x,int n) {
    int res = 1;

    while(n > 0) {
        if(n % 2 != 0) res = res * x;
        x = x*x;
        n = n/2;
    }
    
    return res;
}

int main() {
    // Start writing your code below...
    int n, x;
    std::cout << "enter base power = ";
    std::cin >> n >> x;

    run_function_with_time_calculator(n, x, power_1);

    return 0;
}