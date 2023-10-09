/**
 * Celcius to farenheit
 * 
 * Formula:
 * F = C * (9/5) + 32
*/
#include <iostream>
#include <iomanip>

class Solution {
    public:
        double conv_temp(int C) {
            return C*((double)9/(double)5) + 32;
        }
};

int main() {
    int T;
    std::cin >> T;
    while(T--) {
        int n;
        std::cin >> n;
        Solution ob;
        std::cout << ob.conv_temp(n) << std::endl;
    }
    return 0;
}