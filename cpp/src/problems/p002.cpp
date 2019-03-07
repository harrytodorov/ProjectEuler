// Author: Haralambi Todorov <harrytodorov@gmail.com>
// Created on 28.06.2017

#include <iostream>
#include <cassert>
#include "../utilities.h"

/**
 * Find the sum of the even-valued terms in the Fibonacci sequence whose
 * values do not exceed n.
 * The Fibonacci sequence starts with terms 1 and 2.
 */
int problem002(int n) {
    std::vector<int> fibs;
    int sum = 0;
    generate_fibonacci_less_than(n, 1, 2, fibs);
    for (const auto& fib : fibs) {
        if ((fib % 2) == 0) sum += fib;
    }
    return sum;
}
