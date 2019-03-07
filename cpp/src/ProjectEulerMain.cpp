// Author: Haralambi Todorov <harrytodorov@gmail.com>
// Created on 6.03.2019

#include <chrono>
#include <iostream>

// Problems
#include "problems/p001.cpp"

// Main driver for solving Project Euler problems
int main(int argc, char** argv) {
	// Problem 1
	auto s001 = std::chrono::system_clock::now();
	auto p001_result = problem001(1000);
	auto e001 = std::chrono::system_clock::now();
	std::cout << "Result of problem 001: " << p001_result << std::endl;
	auto ellapsed_milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(e001-s001);
	std::cout << "Solved in " << ellapsed_milliseconds.count() << " milliseconds." << std::endl;
}