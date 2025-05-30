
#include <iostream>
#include <iomanip>
#include <chrono>

inline double calculate(int iterations, double param1, double param2) {
    double result = 1.0;
    for (int i = 1; i <= iterations; ++i) {
        double j = i * param1 - param2;
        result -= (1.0 / j);
        j = i * param1 + param2;
        result += (1.0 / j);
    }
    return result;
}

int main() {
    // Start time measurement
    auto start_time = std::chrono::high_resolution_clock::now();

    double result = calculate(100000000, 4.0, 1.0) * 4;

    // End time measurement
    auto end_time = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> execution_time = end_time - start_time;

    std::cout << std::fixed << std::setprecision(12); // Set precision for output
    std::cout << "Result: " << result << std::endl;
    std::cout << "Execution Time: " << execution_time.count() << " seconds" << std::endl;

    return 0;
}
