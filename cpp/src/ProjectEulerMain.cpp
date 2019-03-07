// Author: Haralambi Todorov <harrytodorov@gmail.com>
// Created on 6.03.2019

#include <chrono>
#include <iostream>

// Problems
#include "problems/p001.cpp"
#include "problems/p002.cpp"

void execute_problem(int (*problem)(int),
					 const int problem_input,
					 const int problem_number) {
	auto s001 = std::chrono::system_clock::now();
	auto p001_result = (*problem)(problem_input);
	auto e001 = std::chrono::system_clock::now();
	std::cout << "Result of problem " << problem_number
			  << ": " << p001_result << std::endl;
	auto ellapsed_milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(e001-s001);
	std::cout << "Solved in " << ellapsed_milliseconds.count()
			  << " milliseconds." << std::endl;
	std::cout << "---" << std::endl;
}

// Main driver for solving Project Euler problems
int main(int argc, char** argv) {
	// Problem 1
	execute_problem(problem001, 1000, 1);

	// Probmlem 2
	execute_problem(problem002, 4000000, 2);

}