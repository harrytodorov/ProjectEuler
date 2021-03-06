// Author: Haralambi Todorov <harrytodorov@gmail.com>
// Created on 09.07.2017

#include <cassert>
#include <iostream>
#include <vector>
#include <unordered_map>

enum figurativeType {
  tri,
  sqr,
  pen,
  hex,
  hep,
  oct
};

inline uint32_t triangle(const uint32_t &n) {
  return n * (n + 1) / 2;
}

inline uint32_t square(const uint32_t &n) {
  return n * n;
}

inline uint32_t pentagon(const uint32_t &n) {
  return n * (3 * n - 1) / 2;
}

inline uint32_t hexagon(const uint32_t &n) {
  return n * (2 * n - 1);
}

inline uint32_t heptagon(const uint32_t &n) {
  return n * (5 * n - 3) / 2;
}

inline uint32_t octagon(const uint32_t &n) {
  return n * (3 * n - 2);
}

inline bool criteria(const uint32_t &front, const uint32_t &back) {
  return (back / 100) == (front % 100);
}

std::vector<uint32_t> generate_pairs(const figurativeType &type) {
  uint32_t ni{1}, n{0};
  std::vector<uint32_t> r;

  while (n < 10000) {
    switch (type) {
      case tri:
        // triangle number
        n = triangle(ni);
        break;
      case sqr:
        // square number
        n = square(ni);
        break;
      case pen:
        // pentagon number
        n = pentagon(ni);
        break;
      case hex:
        // hexagon number
        n = hexagon(ni);
        break;
      case hep:
        // heptagon number
        n = heptagon(ni);
        break;
      case oct:
        // octagon number
        n = octagon(ni);
        break;
    }
    if (n > 999 && n < 10000)
      r.push_back(n);
    ni++;
  }
  return r;
}

void tests() {
  // test triangle number generation
  assert(1 == triangle(1));
  assert(3 == triangle(2));
  assert(6 == triangle(3));
  assert(10 == triangle(4));
  assert(15 == triangle(5));

  // test square number generation
  assert(1 == square(1));
  assert(4 == square(2));
  assert(9 == square(3));
  assert(16 == square(4));
  assert(25 == square(5));

  // test pentagonal number generation
  assert(1 == pentagon(1));
  assert(5 == pentagon(2));
  assert(12 == pentagon(3));
  assert(22 == pentagon(4));
  assert(35 == pentagon(5));

  // test hexagonal number generation
  assert(1 == hexagon(1));
  assert(6 == hexagon(2));
  assert(15 == hexagon(3));
  assert(28 == hexagon(4));
  assert(45 == hexagon(5));

  // test heptagonal number generation
  assert(1 == heptagon(1));
  assert(7 == heptagon(2));
  assert(18 == heptagon(3));
  assert(34 == heptagon(4));
  assert(55 == heptagon(5));

  // test octagonal number generation
  assert(1 == octagon(1));
  assert(8 == octagon(2));
  assert(21 == octagon(3));
  assert(40 == octagon(4));
  assert(65 == octagon(5));

  // test getting criteria
  assert(criteria(8128, 2882));
  assert(criteria(2882, 8128));
  assert(criteria(1921, 2140));

}

int main() {

  // vector to contain pairs of parameter and its corresponding triangle
  // number, which is in range [1000, 9999].
  std::vector<uint32_t> triangles = generate_pairs(tri);
  std::vector<uint32_t> squares = generate_pairs(sqr);
  std::vector<uint32_t> pentagons = generate_pairs(pen);
  std::vector<uint32_t> hexagons = generate_pairs(hex);
  std::vector<uint32_t> heptagons = generate_pairs(hep);
  std::vector<uint32_t> octagons = generate_pairs(oct);

  std::unordered_map<uint8_t, std::vector<uint32_t>> figurative_numbers;
  figurative_numbers = {
      {3, triangles},
      {4, squares},
      {5, pentagons},
      {6, hexagons},
      {7, heptagons},
      {8, octagons}
  };

  // Figurative number permutations.
  std::vector<int> ftp = {3, 4, 5, 6, 7, 8};

  // Go through all possible permutations (starting with octagons) of the
  // figurative number types, and try to find a set of the six numbers, which
  // fulfill the given criteria.
  size_t i = 0;
  bool found = false;
  do {
    if (found) break;
    i++;
    if (i < 601) continue;

    for (unsigned int &ftp1 : figurative_numbers[ftp[0]]) {
      if (found) break;

      for (unsigned int &ftp2 : figurative_numbers[ftp[1]]) {
        if (found) break;
        if (!criteria(ftp1, ftp2)) continue;

        for (unsigned int &ftp3 : figurative_numbers[ftp[2]]) {
          if (found) break;
          if (!criteria(ftp2, ftp3)) continue;

          for (unsigned int &ftp4 : figurative_numbers[ftp[3]]) {
            if (found) break;
            if (!criteria(ftp3, ftp4)) continue;

            for (unsigned int &ftp5 : figurative_numbers[ftp[4]]) {
              if (found) break;
              if (!criteria(ftp4, ftp5)) continue;

              for (unsigned int &ftp6 : figurative_numbers[ftp[5]]) {
                if (!criteria(ftp5, ftp6)) continue;
                if (!criteria(ftp6, ftp1)) continue;
                std::cout << "Permutation: " << ftp[0] << ", " << ftp[1]
                          << ", " << ftp[2] << ", " << ftp[3] << ", "
                          << ftp[4] << ", " << ftp[5] << std::endl;
                std::cout << "Set: " << ftp1 << ", " << ftp2 << ", " << ftp3
                          << ", " << ftp4 << ", " << ftp5 << ", " << ftp6
                          << std::endl;
                std::cout << "Sum: " << ftp1 + ftp2 + ftp3 + ftp4 + ftp5 + ftp6
                          << std::endl;
                found = true;
                break;
              }
            }
          }
        }
      }
    }
  } while (std::next_permutation(ftp.begin(), ftp.end()));
}
