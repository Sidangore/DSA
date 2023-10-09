#include <iostream>
#include <iomanip>

int trail_zeroes_fact2(int n) {
    int res = 0;
    for (int i = 5; i <= n; i = i * 5) {
        res += n/i;
    }
    return res;
}

int main() {
    // Start writing your code below...

    int n;
    std::cin >> n;
    std::cout << trail_zeroes_fact2(n) << std::endl;

    return 0;
}