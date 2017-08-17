//
// Created by Haralambi Todorov on 17/08/2017.
//

/// Problem 3:
/// The prime factors of 13195 are 5, 7, 13 and 29.
/// What is the largest prime factor of the number 600851475143 ?

#include <vector>
#include <iostream>
#include "utilities.h"

int main() {
    std::vector<uint64_t> primes;
    uint64_t n{100000};
    uint64_t l{0};

    // generate primes less than n
    generate_primes_less_than(n, primes);

    // iterate through the iterated primes and see if they're factors of
    // the given number
    for (auto a : primes) {

        // if yes, and the prime is larger than the currently largest found prime,
        // assign a to l
        if (600851475143 % a == 0 && a > l)
            l = a;
    }

    std::cout << "The largest prime factor of 600851475143 is: " << l << std::endl;
}