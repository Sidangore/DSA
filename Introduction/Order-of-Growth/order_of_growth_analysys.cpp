#include <iostream>
#include <iomanip>

int linear_search(int arr[], int n, int x) {
    for(int i = 0; i< n; i++) {
        if(x == arr[i]) return i;
    }
    return -1;
}

int main() {
    // To get the high precision execution time in s
    time_t start, end;
    time(&start);
    std::ios_base::sync_with_stdio(false);
    // Write your code from below

    int arr[] = {1, 3, 5, 4, 6, 4, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 9;

    // Ending the time of execution
    time(&end);
    std::cout << "X: " << x << " is found at " << linear_search(arr, n, x) << std::endl;

    double time_taken = double(end - start);
    std::cout << "Time taken by program = " << std::fixed << std::setprecision(5) << time_taken << "s" << std::endl;

    return 0;
}
