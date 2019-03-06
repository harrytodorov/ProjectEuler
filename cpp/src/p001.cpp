//
// Created by Haralambi Todorov on 28/06/2017.
//

/// Problem 1 Statement:
/// If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.
/// Find the sum of all the multiples of 3 or 5 below 1000.

#include <iostream>
#include <numeric>
#include <set>

void multiples_of_3_and_5_below_n(const int n, std::set<int> &ra) {
    // Iterate over the n numbers
    for (int i = 1; i < n; i++) {
        // Check if a number is a multiple of 3/5
        if ((i % 3 == 0) || (i % 5 == 0)) {
            ra.insert(i);
        }
    }
}

int main() {
    std::set<int> res;

    // test if the function works for the given test
    multiples_of_3_and_5_below_n(10, res);
    int res10 = std::accumulate(res.begin(), res.end(), (int) 0);
    std::cout << "Sum of multiples of 3 and 5 below 10: " << res10 << std::endl;

    // clear the set holding the result
    res.clear();

    // test for input of 1000
    multiples_of_3_and_5_below_n(1000, res);
    int res1000 = std::accumulate(res.begin(), res.end(), (int) 0);
    std::cout << "Sum of multiples of 3 and 5 below 10: " << res1000 << std::endl;
}