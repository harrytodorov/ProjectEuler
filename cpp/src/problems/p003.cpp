//
// Created by Haralambi Todorov on 17/08/2017.
//

#include <iostream>
#include <vector>
#include <cassert>
#include "utilities.h"

int main() {
    // A small test case
    int number_to_test = 13195;
    int largest_prime = 0;
    std::vector<int> prime_factors;
    generate_primes_less_than(number_to_test, prime_factors);

    // The generated primes are sorted ascendingly
    for (const auto &prime : prime_factors) {
        if (number_to_test % prime == 0) {
            largest_prime = prime;
        }
    }
    assert(largest_prime == 29);

    // // generate primes less than n
    // generate_primes_less_than(n, primes);

    // // iterate through the iterated primes and see if they're factors of
    // // the given number
    // for (auto a : primes) {

    //     // if yes, and the prime is larger than the currently largest found prime,
    //     // assign a to l
    //     if (600851475143 % a == 0 && a > l)
    //         l = a;
    // }

    // std::cout << "The largest prime factor of 600851475143 is: " << l << std::endl;
}