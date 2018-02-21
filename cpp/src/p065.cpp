// Copyright (c) 2018, University of Freiburg.
// Author: Haralambi Todorov <harrytodorov@gmail.com>

/// Convergents of e
/// e = [2; 1,2,1, 1,4,1, 1,6,1 , ... , 1,2k,1, ...].
/// The first ten terms in the sequence of convergents for e are:
/// 2
/// 2 + 1/1 = 3
/// 2 + 1/(1 + (1/2)) = 8/3
/// 2 + 1/(1 + 1/(2 + 1/1)) = 11/4
/// ...
/// 10th: ... = 1457/536
/// The sum of digits in the numerator of the 10th convergent is 1+4+5+7=17.
/// Find the sum of digits in the numerator of the 100th convergent of the
/// continued fraction for e.

#include <cstdint>
#include <cassert>
#include <vector>
#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>

using namespace boost::multiprecision;

struct fraction {
  int256_t n; // numerator
  int256_t d; // denominator
  fraction(const int256_t &_n,
           const int256_t &_d) : n(_n), d(_d) {}
};

fraction add_int_to_frac(const int256_t &i,
                         const fraction &f) {
  return fraction(i * f.d + f.n, f.d);
}

fraction int_over_frac(const int256_t &i,
                       const fraction &f) {
  return fraction(f.d * i, f.n);
}

std::vector<size_t> e_sequence(const size_t &n) {
  std::vector<size_t> res;
  res.push_back(2);
  size_t i = 1;
  while (res.size() < n) {
    if ((res.size() + 1) % 3 == false) {
      res.push_back(2 * i);
      i++;
    } else {
      res.push_back(1);
    }
  }
  return res;
}

int256_t sum_digits(const int256_t &i) {
  int256_t sum = i % 10;
  int256_t _i = i / 10;
  while (_i > 0) {
    sum += (_i % 10);
    _i /= 10;
  }
  return sum;
}

void tests() {
  assert(fraction(4, 3).n == add_int_to_frac(1, fraction(1, 3)).n);
  assert(fraction(4, 3).d == add_int_to_frac(1, fraction(1, 3)).d);

  assert(fraction(11, 4).n == add_int_to_frac(2, fraction(3, 4)).n);
  assert(fraction(11, 4).d == add_int_to_frac(2, fraction(3, 4)).d);

  assert(fraction(3, 4).n == int_over_frac(1, fraction(4, 3)).n);
  assert(fraction(3, 4).d == int_over_frac(1, fraction(4, 3)).d);

  assert(17 == sum_digits(1457));
}

int main() {
  // Generate first n numbers of the e convergence sequence.
  size_t n = 100;
  std::vector<size_t> e_seq = e_sequence(n);

  // Compute the convergence of e until n.
  fraction curr(1, e_seq[e_seq.size() - 1]);
  int i = e_seq.size() - 2;
  while (i >= 0) {
    if (i == 0) {
      curr = add_int_to_frac(e_seq[i], curr);
    } else {
      curr = int_over_frac(1, add_int_to_frac(e_seq[i], curr));
    }
    i--;
  }

  std::cout << "Result: " << curr.n << "/" << curr.d << std::endl;
  std::cout << "Sum of the digits in the numerator: " << sum_digits(curr.n)
            << std::endl;
  return 0;
}