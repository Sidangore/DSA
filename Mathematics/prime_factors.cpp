#include <iostream>
#include <iomanip>

/**
 * Optimised prime factors solution
 * 
 * Here, if the n ≤ 1 => There are no prime factors => return;
 * Divisibility by 2 & 3 is considered for optimizing,
 * as it reduces the work done by 3 times.
 * 
 * For example, given numbers
 * 2, 3, 4, 5, 6, 7, 8, 9,
 * 10, 11, 12, 13, 14, 15, 16, 17, 18, 19,
 * 20, 21, 22, 23, 24, 25, 26, 27, 28, ...n^0.5 (i.e. till sq. root of n).
 * 
 * Now, divisibility of 2 is checked
 * => 3, 5, 7, 9,
 * 11, 13, 15, 17, 19,
 * 21, 23, 25, 27, ...n^0.5 (i.e. till sq. root of n).
 * => Almost half of the numbers are eliminated.
 * 
 * Now, after considering divisibility of 3,
 * => 5, 7,
 * 11, 13, 17, 19,
 * 23, 25, ...n^0.5 (i.e. till sq. root of n).
 * => Almost quarter of the numbers are eliminated.
 * 
 * Now, the pattern can be seen as,
 * i = 5  & (i+2) = 7,
 * i = i + 6 => 11, & (i+2) = 13,
 * i = i + 6 => 17, & (i+2) = 19, ...
 * 
 * Therefore, the for loop will start from int i = 5,
 * & will be incremented by 6 => i += 6
 * 
 * Time complexity in the worst case is that it is a prime factor
 * = O(n^0.5)
*/
void prime_factors(int n) {
    if(n <= 1) return;
    while(n % 2 == 0) {
        std::cout << 2  << " ";
        n /= 2;
    }
    while(n % 3 == 0) {
        std::cout << 3 << " ";
        n /= 3;
    }
    for(int i = 5; i * i <= n; i += 6) {
        while(n % i == 0) {
            std::cout << i << " ";
            n /= i;
        }
        while(n % (i + 2) == 0) {
            std::cout << (i+2) << " ";
            n /= (i+2);
        }
    }
    if(n >  3) {
        std::cout << n << " ";
    }
    std::cout << std::endl;
}

int main() {
    // Start writing your code below...
    int n;
    std::cin >> n;

    prime_factors(n);

    return 0;
}