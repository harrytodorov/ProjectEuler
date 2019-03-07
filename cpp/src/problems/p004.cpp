// Author: Haralambi Todorov <harrytodorov@gmail.com>
// Created on 17.08.2017

#include <iostream>
#include <cmath>
#include <vector>

bool isPalindrome(const int n) {
  // Could not be a palindrome.
  // One does not consider negative numbers.
  if (n < 10)
    return false;
  int numberOfDigitis = static_cast<int>(log10(n) + 1);
  int nCopy = n;
  int multiple = static_cast<int>(pow(10, numberOfDigitis / 2 - 1));
  int palindrome = (nCopy % 10) * multiple;
  nCopy /= 10;
  while (nCopy >= palindrome && multiple > 0) {
    if (nCopy == palindrome)
      return true;
    multiple /= 10;
    palindrome += (nCopy % 10) * multiple;
    nCopy /= 10;
  }
  return false;
}

int main() {
  std::vector<std::pair<bool, bool>> digits;
  digits.reserve(998001);
  std::fill(digits.begin(), digits.end(), std::make_pair(false, false));

  size_t max = 0;
  for (size_t i = 100; i < 1000; i++) {
    for (size_t j = 100; j < 1000; j++) {
      if (!digits[i*j].first) {
        digits[i*j].first = true;
        digits[i*j].second = isPalindrome(i*j);
        if (digits[i*j].second && max < i*j) max = i*j;
      }
    }
  }
  std::cout << "Largest palindrome made from product of 3-digit numbers: " <<
            max << std::endl;
}