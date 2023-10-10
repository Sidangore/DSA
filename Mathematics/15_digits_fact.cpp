/**
 * Number of digits in a number
 * 
 * => floor(log10(N) + 1)
*/
#include <iostream>
#include <iomanip>

class Solution {
    public:
        int function_1(int N) {
            if(N <= 0) return 1;
            double digit_count = 1;
            for(int i = N; i >= 1; i--) {
                digit_count += log10(i);
            }
            return floor(digit_count);
        }
};

int main() {
    int T;
    std::cin >> T;
    while(T--) {
        int n;
        std::cin >> n;
        Solution ob;
        std::cout << ob.function_1(n) << std::endl;
    }
    return 0;
}