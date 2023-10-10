/**
 *
*/
#include <iostream>
#include <iomanip>

class Solution {
    public:
        int mod_inv(int a, int m) {
            a = a%m;

            for(int i = 1; i < m; i++) {
                if((a*i)%m == 1) return i;
            }

            return -1;
        }
};

int main() {
    int T;
    std::cin >> T;
    while(T--) {
        int a, m;
        std::cin >> a >> m;
        Solution ob;
        std::cout << ob.mod_inv(a, m) << std::endl;
    }
    return 0;
}