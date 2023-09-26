#include <iostream>
#include <iomanip>
#include <ios> 


/*
    Order of growth is Linear.
*/
int getSum(int arr[], int n) {
    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum;
}
int main() {
    time_t start, end;
    time(&start);
    std::ios_base::sync_with_stdio(false);

    int a[] = {1, 2, 3, 5, 6};
    int n = sizeof(a) / sizeof(a[0]);

    time(&end);
    double time_taken = double(end - start);
    std::cout << getSum(a, n) << "\nTime taken = " << std::fixed << time_taken << std::setprecision(5) << std::endl;

    return 0;
}