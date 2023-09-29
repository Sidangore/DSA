#include <iostream>
#include <iomanip>
#include <cstdlib>

void run_function_with_time_calculator(int n, void (*function) (int)) {
    // To get the high precision execution time in s
    clock_t start, end;
    start = clock();

    // Call your function here
    function(n);

    // Ending the time of execution
    end = clock();

    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    std::cout << "Time taken by program = " << std::fixed << time_taken << std::setprecision(5) << "s" << std::endl;
}

void generate_n_random_numbers(int n) {
    std::cout << "{ ";
    for(int i = 0; i < n; i++) {
        std::cout << rand() << ", ";
    }
    std::cout << "}" << std::endl;
}

void generate_1_random_number() {
    std::cout << rand() << std::endl;
}

void generate_n_random_numbers_from_0_to_x(int n, int x) {
    std::cout << "{ ";
    for(int i = 0; i < n; i++) {
        std::cout << rand() % (x + 1) << ", ";
    }
    std::cout << "}" << std::endl;
}

void generate_1_random_number_from_0_to_x(int x) {
        std::cout << rand() % (x + 1) << std::endl;
}

void generate_n_random_numbers_in_range(int n, int l, int u) {
    std::cout << "{ ";
    for(int i = 0; i < n; i++) {
        std::cout << (rand() % (u - l + 1)) + l << ", ";
    }
    std::cout << "}" << std::endl;
}

void generate_1_random_numbers_in_range(int l, int u) {
    std::cout << (rand() % (u - l + 1)) + l << std::endl;
}


void show_menu() {
    int choice = -1;
    int n, x, y;

    std::cout << "\nGENERATE RANDOM NUMBERS MENU\n1. Generate N random numbers\n2. Generate 1 random number\n3. Generate N random numbers from 0 to X\n4. Generate 1 random number from 0 to X\n5. Generate N random numbers in a range\n6. Generate 1 random numbers in a range\nEnter your choice = ";
    std::cin >> choice;

    switch (choice)
    {
    case 1:
        std::cout << "\nEnter N = ";
        std::cin >> n;
        run_function_with_time_calculator(n, &generate_n_random_numbers);
        break;
    case 2:
        generate_1_random_number();
        break;
    case 3:
        std::cout << "\nEnter N = ";
        std::cin >> n;
        std::cout << "Enter X = ";
        std::cin >> x;
        generate_n_random_numbers_from_0_to_x(n, x);
        break;
    case 4:
        std::cout << "\nEnter X = ";
        std::cin >> x;
        generate_1_random_number_from_0_to_x(x);
        break;
    case 5:
        std::cout << "\nEnter N = ";
        std::cin >> n;
        std::cout << "Enter lower bound = ";
        std::cin >> x;
        std::cout << "Enter upper bound = ";
        std::cin >> y;
        generate_n_random_numbers_in_range(n, x, y);
        break;
    case 6:
        std::cout << "\nEnter lower bound = ";
        std::cin >> x;
        std::cout << "Enter upper bound = ";
        std::cin >> y;
        generate_1_random_numbers_in_range(x, y);
        break;
    default:
        break;
    }
}

int main() {    
    // Write your code from below - To generate set of random numbers
    show_menu();
    
    return 0;
}

