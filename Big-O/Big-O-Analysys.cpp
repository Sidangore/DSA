#include <iostream>
using namespace std;

int main () {
    int a = 0, b = 0;
    int N = 5, M = 5;

    for (int i = 0; i < N; i++) {
        a = a + 5;
    }

    for (int i = 0; i < M; i++) {
        b = b + 10;
    }

    cout << a << " " << b << endl;
    return 0;
}

/**
 * Here the first loop runs for N times 0 -> N-1
 * And second loop runs for M times 0 -> M-1
 * 
 * The calculation time = O(1)
 * So adding the time complexities = O(N+M+1) = O(M+N)
*/