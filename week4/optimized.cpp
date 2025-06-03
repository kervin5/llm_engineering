#include <iostream>
#include <vector>
#include <cstdint>
#include <chrono>
#include <algorithm>

// Linear Congruential Generator function
uint32_t lcg_next(uint32_t& value, uint32_t a = 1664525, uint32_t c = 1013904223, uint64_t m = 1ULL << 32) {
    value = (a * value + c) % m;
    return value;
}

// Calculates the maximum subarray sum using the random numbers generated
int64_t max_subarray_sum(size_t n, uint32_t seed, int min_val, int max_val) {
    std::vector<int> random_numbers(n);
    uint64_t range = max_val - min_val + 1;
    for (size_t i = 0; i < n; ++i) {
        random_numbers[i] = lcg_next(seed) % range + min_val;
    }

    int64_t max_sum = INT64_MIN;
    for (size_t i = 0; i < n; ++i) {
        int64_t current_sum = 0;
        for (size_t j = i; j < n; ++j) {
            current_sum += random_numbers[j];
            max_sum = std::max(max_sum, current_sum);
        }
    }
    return max_sum;
}

// Executes the max subarray sum calculation across 20 different seeds
int64_t total_max_subarray_sum(size_t n, uint32_t initial_seed, int min_val, int max_val) {
    int64_t total_sum = 0;
    uint32_t seed = initial_seed;
    for (int i = 0; i < 20; ++i) {
        lcg_next(seed);
        total_sum += max_subarray_sum(n, seed, min_val, max_val);
    }
    return total_sum;
}

int main() {
    // Parameters
    size_t n = 10000;
    uint32_t initial_seed = 42;
    int min_val = -10;
    int max_val = 10;

    // Timing the function
    auto start_time = std::chrono::high_resolution_clock::now();
    int64_t result = total_max_subarray_sum(n, initial_seed, min_val, max_val);
    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> execution_time = end_time - start_time;

    // Print results
    std::cout << "Total Maximum Subarray Sum (20 runs): " << result << std::endl;
    std::cout << "Execution Time: " << execution_time.count() << " seconds" << std::endl;

    return 0;
}
