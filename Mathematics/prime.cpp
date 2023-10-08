#include <iostream>
#include <iomanip>
/**
 * Optimised solution
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
 * 11, 13, 17, 19,
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
    if(n == 1) return false;
    if(n == 2 || n == 3) return true;
    if(n%2 == 0 || n%3 == 0) return false;
    for(int i = 5; i*i <= n; i+=6) {
        if(n%i == 0 || n%(i+2) == 0) return false;
    }
    return true;
}

int main() {
    // Start writing your code below...
    int n = 101;
    std::cout << is_prime(n) << std::endl;

    return 0;
}