// Author: Haralambi Todorov <harrytodorov@gmail.com>
// Created on 28.06.2017

#include <iostream>
#include <cassert>
#include "utilities.h"

int main() {

    // A small test case
    // Find the sum of the even valued terms of the first 10 Fibonacci numbers
    // starting with 1 and 2
    // {2, 8, 34} = 44
    std::vector<int> fibs;
    int sum = 0;
    generate_fibonacci_numbers(10, 1, 2, fibs);
    for (const auto& fib : fibs) {
        if ((fib % 2) == 0) sum += fib;
    }
    assert(sum == 44);

    // Problem case
    sum = 0;
    fibs.clear();
    generate_fibonacci_less_than(4000000, 1, 2, fibs);
    for (const auto& fib : fibs) {
        if ((fib % 2) == 0) sum += fib;
    }

    std::cout << "Sum of fibonacci numbers which do not exceed 4,000,000 "
              << "and are even is: " <<  sum << std::endl;
}