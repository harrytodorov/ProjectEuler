//
// Created by Haralambi Todorov on 28/06/2017.
//

/// Problem 2 Statement:
/// Each new term in the Fibonacci sequence is generated by adding the previous two terms. By starting with 1 and 2, the first 10 terms will be:
///             1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...
/// By considering the terms in the Fibonacci sequence whose values do not exceed four million, find the sum of the even-valued terms.

#include <cstdio>

inline int next_fibonacci_term(const int &f1, const int &f2) {
    return f1 + f2;
}

int main() {
    int f1(1), f2(2), i(2), tmp, sum(0);

    // test if the program works for the given test scenario
    {
        while (i < 10) {
            // add f2 to the sum, if it's even
            if (f2 % 2 == 0) sum += f2;

            tmp = f1;
            f1 = f2;
            f2 = next_fibonacci_term(tmp, f1);

            i++;
        }
        printf("Sum of first 10 fibonacci numbers which are even is: %d\n", sum);
    }

    // run the program for the problem input
    {
        // reset the values for the sum, f1 and f2
        sum = 0;
        f1 = 1;
        f2 = 2;

        while (f2 < 4000000) {
            // add f2 to the sum, if it's even
            if (f2 % 2 == 0) sum += f2;

            tmp = f1;
            f1 = f2;
            f2 = next_fibonacci_term(tmp, f1);
        }
        printf("Sum of fibonacci numbers which do not exceed 4,000,000 and are even is: %d\n", sum);
    }
}