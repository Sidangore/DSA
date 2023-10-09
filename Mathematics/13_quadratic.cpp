/**
 * Quadratic roots
 * 
 * In a quadratic eqn ax^2 + bx + c = 0
 * 
 * Roots will be = -b ± √(b^2 - 4ac) / 2a
 * 
 * The roots will be decided by D = √(b^2 - 4ac)
 * If D > 0 => Real and distinct
 * If D = 0 => Read and equal
 * If D < 0 => Imaginary roots
*/

/**
 *
*/
#include <iostream>

class Solution {
    public:
        std::vector<int> quadratic(int a, int b, int c) {
            std::vector<int> roots;
            double D = b*b - 4*a*c, root_1 = -1, root_2;

            if(D < 0) {
                roots.push_back(root_1);
                return roots;                
            }
            else if(D >= 0) {
                root_1 = floor((-b + sqrt(D)) / (2*a));
                root_2 = floor((-b - sqrt(D)) / (2*a));
            } 
            if(root_1 > root_2) {
                roots.push_back(root_1);
                roots.push_back(root_2);
            } else {
                roots.push_back(root_2);
                roots.push_back(root_1);
            }

            return roots;
        }
};

int main() {
    int T;
    std::cin >> T;
    while(T--) {
        int a, b, c;
        std::cin >> a >> b >> c;
        Solution ob;

        std::vector<int> roots = ob.quadratic(a, b, c);

        if(roots.size() == 1 && roots[0] == -1) std::cout << "Imaginary";
        else for(int i = 0; i < roots.size(); i++) std::cout << roots[i] << " ";
        std::cout << std::endl;
    }
    return 0;
}