//
// Created by Haralambi Todorov on 28/06/2017.
//

/// Problem 1 Statement:
/// If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.
/// Find the sum of all the multiples of 3 or 5 below 1000.

#include <cmath>
#include <numeric>
#include <set>

void multiples_of_3_and_5_below_n(const int n, std::set<int> &ra) {
    int i = 1;
    int p3, p5;
    while (i*3 < n) {
        // calculate 3 & 5 to the power i
        p3 = 3*i;
        p5 = 5*i;

        // because set only can contain unique elements, we don't have to double check
        // if the element we're inserting is already contained in the resulting set

        ra.insert(p3);

        // add p5 to the resulting set only if its less than n
        if (p5 < n)
            ra.insert(p5);

        // increment i
        i++;
    }
}

int main() {
    std::set<int> res;

    // test if the function works for the given test
    multiples_of_3_and_5_below_n(10, res);
    int res10 = std::accumulate(res.begin(), res.end(), (int) 0);
    printf("Sum of multiples of 3 and 5 below 10: %d\n", res10);

    // clear the vector holding the result
    res.clear();

    // test for input of 1000
    multiples_of_3_and_5_below_n(1000, res);
    int res1000 = std::accumulate(res.begin(), res.end(), (int) 0);
    printf("Sum of multiples of 3 and 5 below 1000: %d\n", res1000);
}
