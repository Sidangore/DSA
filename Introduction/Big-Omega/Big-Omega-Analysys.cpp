#include <stdcpp.h>
using namespace std;

int print(int a[], int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i != j) cout << a[i] << " " << a[j] << endl;
        }
    }
    return -1;
}

int main() {
    int a[] = {1, 2, 3};
    int n = sizeof(a) / sizeof(a[0]);

    print(a, n);

    return 0;
}