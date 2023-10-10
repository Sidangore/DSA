/**
 * ADDITION UNDER MODULO
 * 10^9 + 7
 * 1000000007
*/
#include <iostream>
#include <iomanip>

class Solution {
    public:
        long long sumUnderModulo(long long A, long long B) {
            long long m = 1000000007;
            long long i = A % m, j = B % m;

            return (i + j) % m;
        }
};

int main() {
    int T;
    std::cin >> T;
    while(T--) {
        long long A, B;
        std::cin >> A >> B;
        Solution ob;
        std::cout << ob.sumUnderModulo(A, B) << std::endl;
    }
    return 0;
}