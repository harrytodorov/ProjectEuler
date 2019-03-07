// Author: Haralambi Todorov <harrytodorov@gmail.com>
// Created on 17.08.2017

#ifndef PROJECTEULER_UTILITIES_H
#define PROJECTEULER_UTILITIES_H

#include <cmath>
#include <vector>

/**
 * Generates a sequence of Fibonacci numbers given the first two terms fib1 
 * and fib2, where the last number of the sequence is less than n.
 */
void generate_fibonacci_less_than(const int less_than,
                                  const int fib1,
                                  const int fib2,
                                  std::vector<int> &fibonacci_nums) {
    // Clear the vector conents and adds the first two memebers
    fibonacci_nums.clear();
    fibonacci_nums.push_back(fib1);
    fibonacci_nums.push_back(fib2);

    if (less_than <= fib2) return;

    int current_fib = fib1 + fib2;
    int i = fibonacci_nums.size() - 1;
    while (current_fib < less_than) {
        fibonacci_nums.push_back(current_fib);
        i++;
        current_fib = fibonacci_nums[i] + fibonacci_nums[i-1];
    }
}

/**
 * Generates the first n Fibonacci numbers given the first two terms fib1 
 * and fib2.
 */
void generate_fibonacci_numbers(const int n,
                                const int fib1,
                                const int fib2,
                                std::vector<int> &fibonacci_nums) {
    // Clear the vector conents and resize it to fit n
    fibonacci_nums.clear();
    fibonacci_nums.reserve(n);
    fibonacci_nums.push_back(fib1);
    fibonacci_nums.push_back(fib2);

    for (int i = fibonacci_nums.size(); i < n; i++) {
        int current_fib = fibonacci_nums[i-1] + fibonacci_nums[i-2];
        fibonacci_nums.push_back(current_fib);
    }
}

/**
 * Generate primes less than an integer n using the sieve of Eratosthenes.
 */
void generate_primes_less_than(const int &n, std::vector<int> &primes) {
    if (n <= 2) return;

    int numbers_to_check = ceil(sqrt(n));
    // Boolean vector holding numbers [0, numbers_to_check] all set to true
    std::vector<bool> ntn(numbers_to_check, true);

    // For each number from [2, numbers_to_check] set its multipliers
    // from the boolean vector to false
    for (int i = 2; i < numbers_to_check; i++) {
        int j = i*i;
        if ((numbers_to_check > j) && ntn.at(i)) {
            while (j < n) {
                ntn.at(j) = false;
                j += i;
            }
        }
    }

    // add the primes to the resulting array
    for (int i = 2; i < n; i++) {
        if (ntn.at(i))
            primes.push_back(i);
    }
}

#endif //PROJECTEULER_UTILITIES_H
