/**
 * Sieve of Eratothenes -> Is to find the prime number ≤ n
*/
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
 * First, we will check if the number is prime or not,
 * If prime, then will print
 * 
 * This will be done for all numbers from 2 to n (inclusive)
 * 
 * * * * * * * * * * * * * * * * * * * *
 * Optimised solution for finding prime
 * 
 * This works 1/3 of the efficient solution.
 * As we are omitting most of the calculation by checking divisibility with 2 & 3.
 * 
 * If a number has divisors x & y => n = x * y
 * if x <= y
 * => x * x <= n
 * => x^2 ≤ n
 * => x ≤ n^(1/2)
 * 
 * Therefore, 1 divisor would be between 2 & n^(1/2),
 * if not, then its a prime.
 * 
 * In the for loop we are incrementing i = i+6,
 * As for example,
 * 1, 2, 3, 4, 5, 6, 7, 8, 9,
 * 10, 11, 12, 13, 14, 15, 16, 17, 18, 19,
 * 20, 21, 22, 23, 24, 25, 26, 27, 28, ...
 * 
 * if we check divisibility by 2 at first, then, 
 * 3, 5, 7, 9,
 * 11, 13, 15, 17, 19,
 * 21, 23, 25, 27, ...
 * 
 * Almost half of the numbers are ruled out, leaving only odd numbers,
 * And now when we check divisibility by 3,
 * 5, 7,
 * 11, 13, 
 * 17, 19,
 * 23, 25, ...
 * More quarter numbers are eliminated.
 * 
 * Now if we look at these numbers we can see the pattern,
 * (i) & (i+2)
 * (i+6) & ((i+2)+2)
 * That's why in the for loop we are starting from 5 and incrementing by 6.
 * 
 * Time complexity = O(n^0.5)
 * Space complexity = O(1) 
*/
bool is_prime(int n) {
    if(n <= 1) return false;
    if(n == 2 || n == 3) return true;
    if(n % 2 == 0 || n % 3 == 0) return false;
    for(int i = 5; i*i <= n; i = i + 6) {
        if(n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}
/**
 * The naive approach continuation
 * 
 * The is_prime() has,
 * Time Complexity = O(√n)
 * Auxiliary Space = O(1)
 * 
 * And primes() goes from 2 to n, i.e. n times
 * Hence, 
 * Time Complexity = O(n * √n)
 * Auxiliary Space = O(1)
*/
void primes(int n) {
    for(int i = 2; i <= n; i++) {
        if(is_prime(i)) std::cout << i << ", ";
    }
    std::cout << std::endl;
}

/**
 * Sieve of Eratothenes 
 * 
 * We make an initial array, arr[n+1] will all values true.
 * Then will check the divisibility by 2, 3 & 5 and mark those locations as false.
 * 
 * 0th and 1st are empty as they do not matter.
 * 
 * The remaining positions with true-values, are prime.
 * 
 * For ex.
 * [0] [1] [2] [3] [4] [5] [6] [7] [8] [9] [10] [11] [12] [13] [14] [15] [16] [17] [18] [19] [20] ... [n]
 *          T   T   T   T   T   T   T   T   T    T    T    T    T    T    T    T    T    T    T   ...  T
 * 
 * If divisible by 2 except 2, mark false
 * [0] [1] [2] [3] [4] [5] [6] [7] [8] [9] [10] [11] [12] [13] [14] [15] [16] [17] [18] [19] [20] ... [n]
 *          T   T   F   T   F   T   F   T   F    T    F    T    F    T    F    T    F    T    F   ...  T
 * 
 * If divisible by 3 except 3, mark false
 * [0] [1] [2] [3] [4] [5] [6] [7] [8] [9] [10] [11] [12] [13] [14] [15] [16] [17] [18] [19] [20] ... [n]
 *          T   T   F   T   F   T   F   F   F    T    F    T    F    F    F    T    F    T    F   ...  T
 * 
 * If divisible by 5 except 5, mark false
 * [0] [1] [2] [3] [4] [5] [6] [7] [8] [9] [10] [11] [12] [13] [14] [15] [16] [17] [18] [19] [20] ... [n]
 *          T   T   F   T   F   T   F   F   F    T    F    T    F    F    F    T    F    T    F   ...  T
 * 
 * Now, the T-elements are, 2, 3, 5, 7, 11, 13, 17, 19... which are primes
 * 
 * Here, we are running from 2 to √n, because,
 * If there is a divisor of n, it will be before √n
 * 
 * So in short,
 * We are going from 2 to √n
 * And marking it false - from the next occurence of the number
*/
void sieve_1(int n) {
    std::vector<bool> prime_vec(n+1, true);
    
    for(int i = 2; i*i <= n; i++) {
        if(prime_vec[i]) {
            for(int j = i+i; j <= n; j = j+i) {
                prime_vec[j] = false;
            }
        }
    }

    for(int i = 2; i <= n; i++) {
        if(prime_vec[i]) std::cout << i << ", ";
    }
    std::cout << std::endl;
}

/**
 * Optimised Sieve of Eratothenes
 * 
 * Here,
 * for(int i = 2; i*i <= n; i++) {
 * We will replace the i*i ≤ n to i ≤ n
 * 
 * & also in for(int j = i+i; j <= n; j = j+i) {
 * We will replace i+i to i*i
 * 
 * Because earlier, (i+i)
 * 5: 10, 15, 20, 25, ...
 * 
 * Now, (i*i)
 * 5: 25, 30, 35, ...
 * 
 * As earlier 10, 15, 20 were marked false again,
 * Despite they were already marked false by 2 & 3
 * 
 * As, for a composite number smaller than i*i
 * i * (i-1)
 * i * (i-2)
 * i * (i-3)
 *      .
 *      .
 *      .
 * i * (i-n)
 * 
 * They are already divisible by smaller number than i
 * 
 * Time Complexity = O(n * loglogn), DON'T KNOW HOW?
 * Auxiliary Space = O(n)
*/
void sieve_2(int n) {
    std::vector<bool> prime_vec(n+1, true);

    for(int i = 2; i <= n; i++) {
        if(prime_vec[i]) {
            std::cout << i << ", ";
            for(int j = i*i; j <= n; j = j+i) {
                prime_vec[j] = false;
            }
        }
    }

    std::cout << std::endl;
}

int main() {
    // Start writing your code below...
    int n;
    std::cout << "Enter n = ";
    std::cin >> n;

    run_function_with_time_calculator(n, sieve_2);

    return 0;
}