//
// Created by Haralambi Todorov on 17/08/2017.
//

#ifndef PROJECTEULER_UTILITIES_H
#define PROJECTEULER_UTILITIES_H

#include <cmath>
#include <vector>

void generate_primes_less_than(const uint64_t &n, std::vector<uint64_t> &primes) {
    // generate primes less than an integer n using the sieve of Eratosthenes

    // boolean vector holding numbers [0, n]
    std::vector<bool> ntn (n, true);

    // for each number from [2, sqrt(n)] set its multipliers from the boolean vector to false
    for (uint64_t i = 2; i < sqrt(n); i++) {
        if (!ntn.empty() && ntn.at(i)) {
            uint64_t j = i*i;
            while (j < n) {
                ntn.at(j) = false;
                j += i;
            }
        }
    }

    // add the primes to the resulting array
    for (uint64_t i = 2; i < n; i++) {
        if (ntn.at(i))
            primes.push_back(i);
    }
}

#endif //PROJECTEULER_UTILITIES_H
