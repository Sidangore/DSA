/**
 * ADDITION UNDER MODULO
 * 10^9 + 7
 * 1000000007
*/
#include <iostream>
#include <iomanip>

class Solution {
    public:
        int multiplicationUnderModulo(long long a, long long b) {
            long long m = 1000000007;
            long long i = a % m, j = b % m;

            return (i * j) % m;
        }
};

int main() {
    int T;
    std::cin >> T;
    while(T--) {
        long long A, B;
        std::cin >> A >> B;
        Solution ob;
        std::cout << ob.multiplicationUnderModulo(A, B) << std::endl;
    }
    return 0;
}