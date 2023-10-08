#include <iostream>
#include <iomanip>

/**
 * Naive solution
 * 
 * Time complexity = O(a*b - max(a,b))
 * Auxilary space = Theta(1)
*/
int lcm(int a, int b) {
    // The LCM would be at least the maximum of a & b.
    int res = std::max(a, b);
    while(true) {
        if(res%a == 0 && res%b == 0) return res;
        res++;
    }
    return res;
}

/**
 * The Optimised solution
 * 
 * As we know that for 2 numbers A & B
 * => A * B = GCD(A, B) x LCM(A, B)
 * 
 * Time complexity of GCD() = O(log(min(a, b)))
 * Auxilary space of GCD() = O(1)
 * 
 * Therefore, Time complexity of LCM() = O(log(min(a, b)))
 * & auxilary space  of LCM() = O(1)
*/
int gcd(int a, int b) {
    if(b == 0) return a;
    return gcd(b, a%b);
}
int lcm_opti(int a, int b) {
    return a*b/gcd(a, b);
}
int main() {
    // Start writing your code below...

    int a = 100, b = 200;
    std::cout << lcm_opti(a, b) << std::endl;

    return 0;
}