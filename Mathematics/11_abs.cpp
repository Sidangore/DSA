#include <iostream>

class Solution {
    public:
        int absolute(int n) {
            return (n < 0) ? -n : n;
        }
};

int main() {
    int T;
    std::cin >> T;
    while(T--) {
        int n;
        std::cin >> n;
        
        Solution ob;
        std::cout << ob.absolute(n) << std::endl;
    }
    return 0;
}


