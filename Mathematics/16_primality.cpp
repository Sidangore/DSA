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
};

int main() {
    int T;
    std::cin >> T;
    while(T--) {
        int n;
        std::cin >> n;
        Solution ob;
        if(ob.function(n)) std::cout << "Yes";
        else std::cout << "No";
        std::cout << std::endl;
    }
    return 0;
}