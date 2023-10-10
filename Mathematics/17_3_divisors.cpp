/**
 *
*/
#include <iostream>
#include <iomanip>

class Solution {
    public:
        bool function(int n) {
            if(n == 1) return false;
            if(n == 2 || n == 3) return true;
            if(n % 2 == 0 || n % 3 == 0) return false;
            for(int i = 5; i*i <= n; i = i + 6) {
                if(n % i == 0 || n % (i+2) == 0) return false;
            }
            return true;
        }

        int exactly3Divisors(int N) {            
            int res = 0;

            for(int i = 1; i*i <= N; i++) {
                if(function(i)) res++;
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