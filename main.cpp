#include <iostream>
#include <conio.h>
#include <ctime>
#include <fstream>
#include <string>
#include <algorithm>
#include "sort.h"
#include "Markdown.h"

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

TEST_CASE("Sequential STL container", "[classic]"){
	const size_t N = 4000000;
	writeColumnsNames();

	clock_t begin_time = clock();
	std::vector<int> vec = generators::generateRandomNumbersContainer<std::vector<int>>(N, 0, 99999);
	sort::radix_sort_stl_containers(vec, 5, 10);
	std::cout << float(clock() - begin_time) / CLOCKS_PER_SEC << std::endl;
	writeResult("Radix", "Sequential", "STL vector", N, 5, float(clock() - begin_time) / CLOCKS_PER_SEC);

	begin_time = clock();
	vec = generators::generateRandomNumbersContainer<std::vector<int>>(N, 0, 9999999999);
	sort::radix_sort_stl_containers(vec, 10, 10);
	std::cout << float(clock() - begin_time) / CLOCKS_PER_SEC << std::endl;
	writeResult("Radix", "Sequential", "STL vector", N, 10, float(clock() - begin_time) / CLOCKS_PER_SEC);

	REQUIRE("0" == "0");
}

TEST_CASE("Sequential STL container std::sort", "[classic]") {
	const size_t N = 4000000;

	clock_t begin_time = clock();
	std::vector<int> vec = generators::generateRandomNumbersContainer<std::vector<int>>(N, 0, 99999);
	std::sort(vec.begin(), vec.end());
	std::cout << float(clock() - begin_time) / CLOCKS_PER_SEC << std::endl;
	writeResult("std::sort", "Sequential", "STL vector", N, 5, float(clock() - begin_time) / CLOCKS_PER_SEC);

	begin_time = clock();
	vec = generators::generateRandomNumbersContainer<std::vector<int>>(N, 0, 9999999999);
	std::sort(vec.begin(), vec.end());
	std::cout << float(clock() - begin_time) / CLOCKS_PER_SEC << std::endl;
	writeResult("std::sort", "Sequential", "STL vector", N, 10, float(clock() - begin_time) / CLOCKS_PER_SEC);

	REQUIRE("0" == "0");
}

TEST_CASE("Sequential dynamic array( N = 4000000)", "[classic]") {
	const size_t N = 4000000;
	std::ofstream outfile("Readme.md", std::ios::app);

	clock_t begin_time = clock();
	int* arr = generators::generateRandomNumbersArray<int>(N, 0, 99999);
	sort::radix_sort_arrays<int>(arr, N, 5, 10);
	std::cout << float(clock() - begin_time) / CLOCKS_PER_SEC << std::endl;
	writeResult("Radix", "Sequential", "Dynamic Array", N, 5, float(clock() - begin_time) / CLOCKS_PER_SEC);	
	delete[] arr;

	begin_time = clock();
	arr = generators::generateRandomNumbersArray<int>(N, 0, 9999999999);
	sort::radix_sort_arrays<int>(arr, N, 10, 10);
	std::cout << float(clock() - begin_time) / CLOCKS_PER_SEC << std::endl;
	writeResult("Radix", "Sequential", "Dynamic Array", N, 10, float(clock() - begin_time) / CLOCKS_PER_SEC);
	delete[] arr;

	REQUIRE("0" == "0");
}

//Write another testing case for OpenMPI
//TEST_CASE("Parallel STL container", "[classic]") {
//	const size_t N = 4000000;
//	std::ofstream outfile("Readme.md");
//
//	clock_t begin_time = clock();
//	std::vector<int> vec = generators::generateRandomNumbersContainer<std::vector<int>>(N, 0, 99999);
//	sort::radix_sort_mpi_stl_containers(vec, 5, 10);
//	std::cout << float(clock() - begin_time) / CLOCKS_PER_SEC << std::endl;
//	outfile << "Radix Parallel STL container (n = " << N << ", digits = " << 5 << "): " << float(clock() - begin_time) / CLOCKS_PER_SEC << "\n" << std::endl;
//
//	/*begin_time = clock();
//	vec = generators::generateRandomNumbersContainer<std::vector<int>>(N, 0, 9999999999);
//	sort::radix_sort_stl_containers(vec, 10, 10);
//	std::cout << float(clock() - begin_time) / CLOCKS_PER_SEC << std::endl;
//	outfile << "Radix Sequential STL container (n = " << N << ", digits = " << 10 << "): " << float(clock() - begin_time) / CLOCKS_PER_SEC << "\n" << std::endl;*/
//
//	//outfile.close();
//
//	REQUIRE("0" == "0");
//}

