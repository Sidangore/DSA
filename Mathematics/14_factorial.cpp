/**
 *
*/
#include <iostream>
#include <iomanip>

class Solution {
    public:
        long long function(int n) {
            long long res = 1;
            for(int i = 1; i <= n; i++) {
                res *= i;
            }
            return res;
        }
};

int main() {
    int T;
    std::cin >> T;
    while(T--) {
        int n;
        std::cin >> n;
        Solution ob;
        std::cout << ob.function(n) << std::endl;
    }
    return 0;
}