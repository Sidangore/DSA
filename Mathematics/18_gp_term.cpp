/**
 * GP Nth Term
 * 
 * T(n) = A * R^(n-1)
*/
#include <iostream>
#include <iomanip>

class Solution {
    public:
        double termOfGP(int A, int B, int N) {
            double R = (double) B / (double) A;
            return A*pow(R, N-1);
        }
};

int main() {
    int T;
    std::cin >> T;
    while(T--) {
        int A, B, N;
        std::cin >> A >> B >> N;
        Solution ob;
        std::cout << floor(ob.termOfGP(A, B, N)) << std::endl;
    }
    return 0;
}