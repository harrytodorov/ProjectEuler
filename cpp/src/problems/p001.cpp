// Author: Haralambi Todorov <harrytodorov@gmail.com>
// Created on 28.06.2017

#include <iostream>
#include <vector>
#include <numeric>

void multiples_of_3_and_5_below_n(const int n, std::vector<int> &multiples) {
    // Iterate over the n numbers
    for (int i = 1; i < n; i++) {
        // Check if a number is a multiple of 3/5
        if ((i % 3 == 0) || (i % 5 == 0)) {
            multiples.push_back(i);
        }
    }
}

/**
 * Find the sum of all natural numbers, which are multiples of 3 or 5
 * below given threshold n.
 */
int problem001(int n) {
    std::vector<int> result;
    multiples_of_3_and_5_below_n(n, result);
    return std::accumulate(result.begin(), result.end(), 0);
}
