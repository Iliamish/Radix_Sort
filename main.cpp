#include <iostream>
#include <conio.h>
#include <ctime>
#include <fstream>
#include <string>
#include <algorithm>
#include "sort.h"

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

TEST_CASE("Sequential STL container", "[classic]"){
	const size_t N = 4000000;
	std::ofstream outfile("Readme.md");
	outfile << "RESULTS:\n" << std::endl;

	clock_t begin_time = clock();
	std::vector<int> vec = generators::generateRandomNumbersContainer<std::vector<int>>(N, 0, 99999);
	sort::radix_sort_stl_containers(vec, 5, 10);
	std::cout << float(clock() - begin_time) / CLOCKS_PER_SEC << std::endl;
	outfile << "Radix Sequential STL container (n = " << N << ", digits = " << 5 << "): " << float(clock() - begin_time) / CLOCKS_PER_SEC << "\n" << std::endl;

	begin_time = clock();
	vec = generators::generateRandomNumbersContainer<std::vector<int>>(N, 0, 9999999999);
	sort::radix_sort_stl_containers(vec, 10, 10);
	std::cout << float(clock() - begin_time) / CLOCKS_PER_SEC << std::endl;
	outfile << "Radix Sequential STL container (n = " << N << ", digits = " << 10 << "): " << float(clock() - begin_time) / CLOCKS_PER_SEC << "\n" << std::endl;

	outfile.close();

	REQUIRE("0" == "0");
}

TEST_CASE("Sequential STL container std::sort", "[classic]") {
	const size_t N = 4000000;
	std::ofstream outfile("Readme.md", std::ios::app);

	clock_t begin_time = clock();
	std::vector<int> vec = generators::generateRandomNumbersContainer<std::vector<int>>(N, 0, 99999);
	std::sort(vec.begin(), vec.end());
	std::cout << float(clock() - begin_time) / CLOCKS_PER_SEC << std::endl;
	outfile << "std::sort Sequential STL container (n = " << N << ", digits = " << 5 << "): " << float(clock() - begin_time) / CLOCKS_PER_SEC << "\n" << std::endl;

	begin_time = clock();
	vec = generators::generateRandomNumbersContainer<std::vector<int>>(N, 0, 9999999999);
	std::sort(vec.begin(), vec.end());
	std::cout << float(clock() - begin_time) / CLOCKS_PER_SEC << std::endl;
	outfile << "std::sort Sequential STL container (n = " << N << ", digits = " << 10 << "): " << float(clock() - begin_time) / CLOCKS_PER_SEC << "\n" << std::endl;

	outfile.close();

	REQUIRE("0" == "0");
}

TEST_CASE("Sequential dynamic array( N = 4000000)", "[classic]") {
	const size_t N = 4000000;
	std::ofstream outfile("Readme.md", std::ios::app);

	clock_t begin_time = clock();
	int* arr = generators::generateRandomNumbersArray<int>(N, 0, 99999);
	int* out = sort::radix_sort_arrays<int>(arr, N, 5, 10);
	std::cout << float(clock() - begin_time) / CLOCKS_PER_SEC << std::endl;
	outfile << "Radix Sequential dynamic array (n = " << N << ", digits = " << 5 << "): " << float(clock() - begin_time) / CLOCKS_PER_SEC << "\n" << std::endl;
	
	delete[] out;

	begin_time = clock();
	arr = generators::generateRandomNumbersArray<int>(N, 0, 9999999999);
	out = sort::radix_sort_arrays<int>(arr, N, 10, 10);
	std::cout << float(clock() - begin_time) / CLOCKS_PER_SEC << std::endl;
	outfile << "Radix Sequential dynamic array (n = " << N << ", digits = " << 10 << "): " << float(clock() - begin_time) / CLOCKS_PER_SEC << "\n" << std::endl;

	delete[] out;

	outfile.close();

	REQUIRE("0" == "0");
}

