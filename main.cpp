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

//#define DEBUG

TEST_CASE("HEADER", "[classic]") {
	writeColumnsNames();
	REQUIRE("0" == "0");
}

#ifdef DEBUG

#else
TEST_CASE("Sequential STL container std::sort 5", "[classic]") {
	const size_t N = 4000000;

	std::vector<int> vec = generators::generateRandomNumbersContainer<std::vector<int>>(N, 0, 99999);
	clock_t begin_time = clock();
	std::sort(vec.begin(), vec.end());
	std::cout << float(clock() - begin_time) / CLOCKS_PER_SEC << std::endl;
	writeResult("std::sort", "Sequential", "STL vector", N, 5, float(clock() - begin_time) / CLOCKS_PER_SEC);

	REQUIRE("0" == "0");
}

TEST_CASE("Sequential STL container std::sort 9", "[classic]") {
	const size_t N = 4000000;

	std::vector<int> vec = generators::generateRandomNumbersContainer<std::vector<int>>(N, 0, 999999999);
	clock_t begin_time = clock();
	std::sort(vec.begin(), vec.end());
	std::cout << float(clock() - begin_time) / CLOCKS_PER_SEC << std::endl;
	writeResult("std::sort", "Sequential", "STL vector", N, 9, float(clock() - begin_time) / CLOCKS_PER_SEC);

	REQUIRE("0" == "0");
}

TEST_CASE("Parallel Sort TBB STL container 5", "[classic]") {
	const size_t N = 4000000;

	clock_t begin_time = clock();
	std::vector<int> vec = generators::generateRandomNumbersContainer<std::vector<int>>(N, 0, 99999);
	tbb::parallel_sort(vec.begin(), vec.end(), [](int a, int b) {
		return a < b;
	});
	std::cout << float(clock() - begin_time) / CLOCKS_PER_SEC << std::endl;
	writeResult("parallel_sort", "Parallel TBB", "STL vector", N, 5, float(clock() - begin_time) / CLOCKS_PER_SEC);

	REQUIRE("0" == "0");
}

TEST_CASE("Parallel Sort TBB STL container 9", "[classic]") {
	const size_t N = 4000000;

	clock_t begin_time = clock();
	std::vector<int> vec = generators::generateRandomNumbersContainer<std::vector<int>>(N, 0, 999999999);
	tbb::parallel_sort(vec.begin(), vec.end(), [](int a, int b) {
		return a < b;
	});
	std::cout << float(clock() - begin_time) / CLOCKS_PER_SEC << std::endl;
	writeResult("parallel_sort", "Parallel TBB", "STL vector", N, 9, float(clock() - begin_time) / CLOCKS_PER_SEC);

	REQUIRE("0" == "0");
}

TEST_CASE("Sequential STL container 5", "[classic]") {
	const size_t N = 4000000;

	std::vector<int> vec = generators::generateRandomNumbersContainer<std::vector<int>>(N, 0, 99999);
	std::vector<int> vec1 = vec, vec2 = vec;
	clock_t begin_time = clock();
	sort::radix_sort_stl_containers(vec1, 5, 10);
	std::cout << float(clock() - begin_time) / CLOCKS_PER_SEC << std::endl;
	writeResult("Radix", "Sequential", "STL vector", N, 5, float(clock() - begin_time) / CLOCKS_PER_SEC);

	std::sort(vec2.begin(), vec2.end());
	bool error = false;
	for (int i = 0; i < vec.size(); i++) {
		if (vec1[i] != vec2[i]) {
			error = true;
			break;
		}
	}
	REQUIRE(!error);
}

TEST_CASE("Sequential STL container 9", "[classic]") {
	const size_t N = 4000000;

	std::vector<int> vec = generators::generateRandomNumbersContainer<std::vector<int>>(N, 0, 999999999);
	std::vector<int> vec1 = vec, vec2 = vec;
	clock_t begin_time = clock();
	sort::radix_sort_stl_containers(vec1, 9, 10);
	std::cout << float(clock() - begin_time) / CLOCKS_PER_SEC << std::endl;
	writeResult("Radix", "Sequential", "STL vector", N, 9, float(clock() - begin_time) / CLOCKS_PER_SEC);

	std::sort(vec2.begin(), vec2.end());
	bool error = false;
	for (int i = 0; i < vec.size(); i++) {
		if (vec1[i] != vec2[i]) {
			std::cout << vec1[i] << " ----- " << vec2[i] << std::endl;
			error = true;
			break;
		}
	}

	REQUIRE(!error);
}


TEST_CASE("Sequential dynamic array( N = 4000000) 5", "[classic]") {
	const size_t N = 4000000;

	int* arr = generators::generateRandomNumbersArray<int>(N, 0, 99999);
	std::vector<int> vec(N);
	for (int i = 0; i < vec.size(); i++) {
		vec[i] = arr[i];
	}

	clock_t begin_time = clock();
	sort::radix_sort_arrays<int>(arr, N, 5, 10);
	std::cout << float(clock() - begin_time) / CLOCKS_PER_SEC << std::endl;
	writeResult("Radix", "Sequential", "Dynamic Array", N, 5, float(clock() - begin_time) / CLOCKS_PER_SEC);

	std::sort(vec.begin(), vec.end());
	bool error = false;
	for (int i = 0; i < vec.size(); i++) {
		if (arr[i] != vec[i]) {
			std::cout << arr[i] << " ----- " << vec[i] << std::endl;
			error = true;
			break;
		}
	}
	delete[] arr;

	REQUIRE(!error);
}

TEST_CASE("Sequential dynamic array( N = 4000000) 9", "[classic]") {
	const size_t N = 4000000;

	int* arr = generators::generateRandomNumbersArray<int>(N, 0, 999999999);
	std::vector<int> vec(N);
	for (int i = 0; i < vec.size(); i++) {
		vec[i] = arr[i];
	}

	clock_t begin_time = clock();
	sort::radix_sort_arrays<int>(arr, N, 9, 10);
	std::cout << float(clock() - begin_time) / CLOCKS_PER_SEC << std::endl;
	writeResult("Radix", "Sequential", "Dynamic Array", N, 9, float(clock() - begin_time) / CLOCKS_PER_SEC);

	std::sort(vec.begin(), vec.end());
	bool error = false;
	for (int i = 0; i < vec.size(); i++) {
		if (arr[i] != vec[i]) {
			std::cout << arr[i] << " ----- " << vec[i] << std::endl;
			error = true;
			break;
		}
	}
	delete[] arr;

	REQUIRE(!error);
}

TEST_CASE("Parallel Radix TBB STL container 5", "[classic]") {
	const size_t N = 4000000;

	std::vector<int> vec = generators::generateRandomNumbersContainer<std::vector<int>>(N, 0, 99999);
	std::vector<int> vec1 = vec, vec2 = vec;
	clock_t begin_time = clock();
	sort::radix_sort_tbb_stl_containers(vec1, 5, 10);
	std::cout << float(clock() - begin_time) / CLOCKS_PER_SEC << std::endl;
	writeResult("Radix", "Parallel TBB", "STL vector", N, 5, float(clock() - begin_time) / CLOCKS_PER_SEC);

	std::sort(vec2.begin(), vec2.end());
	bool error = false;
	for (int i = 0; i < vec.size(); i++) {
		if (vec1[i] != vec2[i]) {
			error = true;
			break;
		}
	}

	REQUIRE(!error);
}

TEST_CASE("Parallel Radix TBB STL container 9", "[classic]") {
	const size_t N = 4000000;

	std::vector<int> vec = generators::generateRandomNumbersContainer<std::vector<int>>(N, 0, 999999999);
	std::vector<int> vec1 = vec, vec2 = vec;
	clock_t begin_time = clock();
	sort::radix_sort_tbb_stl_containers(vec1, 9, 10);
	std::cout << float(clock() - begin_time) / CLOCKS_PER_SEC << std::endl;
	writeResult("Radix", "Parallel TBB", "STL vector", N, 9, float(clock() - begin_time) / CLOCKS_PER_SEC);

	std::sort(vec2.begin(), vec2.end());
	bool error = false;
	for (int i = 0; i < vec.size(); i++) {
		if (vec1[i] != vec2[i]) {
			error = true;
			break;
		}
	}

	REQUIRE(!error);
}


TEST_CASE("Parallel Radix TBB dynamic array( N = 4000000) 5", "[classic]") {
	const size_t N = 4000000;

	clock_t begin_time = clock();
	int* arr = generators::generateRandomNumbersArray<int>(N, 0, 99999);
	std::vector<int> vec(N);
	for (int i = 0; i < vec.size(); i++) {
		vec[i] = arr[i];
	}

	sort::radix_sort_tbb_arrays(arr, N, 5, 10);
	std::cout << float(clock() - begin_time) / CLOCKS_PER_SEC << std::endl;
	writeResult("Radix", "Parallel TBB", "Dynamic Array", N, 5, float(clock() - begin_time) / CLOCKS_PER_SEC);

	std::sort(vec.begin(), vec.end());
	bool error = false;
	for (int i = 0; i < vec.size(); i++) {
		if (arr[i] != vec[i]) {
			std::cout << arr[i] << " ----- " << vec[i] << std::endl;
			error = true;
			break;
		}
	}
	delete[] arr;

	REQUIRE(!error);
}

TEST_CASE("Parallel Radix TBB dynamic array( N = 4000000) 9", "[classic]") {
	const size_t N = 4000000;

	clock_t begin_time = clock();
	int* arr = generators::generateRandomNumbersArray<int>(N, 0, 999999999);
	std::vector<int> vec(N);
	for (int i = 0; i < vec.size(); i++) {
		vec[i] = arr[i];
	}

	sort::radix_sort_tbb_arrays(arr, N, 9, 10);
	std::cout << float(clock() - begin_time) / CLOCKS_PER_SEC << std::endl;
	writeResult("Radix", "Parallel TBB", "Dynamic Array", N, 9, float(clock() - begin_time) / CLOCKS_PER_SEC);

	std::sort(vec.begin(), vec.end());
	bool error = false;
	for (int i = 0; i < vec.size(); i++) {
		if (arr[i] != vec[i]) {
			std::cout << arr[i] << " ----- " << vec[i] << std::endl;
			error = true;
			break;
		}
	}
	delete[] arr;

	REQUIRE(!error);
}

TEST_CASE("Parallel std::thread STL container 5", "[classic]") {
	const size_t N = 4000000;

	std::vector<int> vec = generators::generateRandomNumbersContainer<std::vector<int>>(N, 0, 99999);
	std::vector<int> vec1 = vec, vec2 = vec;
	clock_t begin_time = clock();
	sort::radix_sort_thread_stl_containers(vec1, 5, 10);
	std::cout << float(clock() - begin_time) / CLOCKS_PER_SEC << std::endl;
	writeResult("Radix", "std::thread", "STL vector", N, 5, float(clock() - begin_time) / CLOCKS_PER_SEC);

	std::sort(vec2.begin(), vec2.end());
	bool error = false;
	for (int i = 0; i < vec.size(); i++) {
		if (vec1[i] != vec2[i]) {
			error = true;
			break;
		}
	}
	REQUIRE(!error);
}

TEST_CASE("Parallel std::thread STL container 9", "[classic]") {
	const size_t N = 4000000;

	std::vector<int> vec = generators::generateRandomNumbersContainer<std::vector<int>>(N, 0, 999999999);
	std::vector<int> vec1 = vec, vec2 = vec;
	clock_t begin_time = clock();
	sort::radix_sort_thread_stl_containers(vec1, 9, 10);
	std::cout << float(clock() - begin_time) / CLOCKS_PER_SEC << std::endl;
	writeResult("Radix", "std::thread", "STL vector", N, 9, float(clock() - begin_time) / CLOCKS_PER_SEC);

	std::sort(vec2.begin(), vec2.end());
	bool error = false;
	for (int i = 0; i < vec.size(); i++) {
		if (vec1[i] != vec2[i]) {
			error = true;
			break;
		}
	}
	REQUIRE(!error);
}

TEST_CASE("Parallel std::thread array 5", "[classic]") {
	const size_t N = 4000000;

	clock_t begin_time = clock();
	int* arr = generators::generateRandomNumbersArray<int>(N, 0, 99999);
	std::vector<int> vec(N);
	for (int i = 0; i < vec.size(); i++) {
		vec[i] = arr[i];
	}

	sort::radix_sort_tbb_arrays(arr, N, 5, 10);
	std::cout << float(clock() - begin_time) / CLOCKS_PER_SEC << std::endl;
	writeResult("Radix", "Parallel TBB", "Dynamic Array", N, 5, float(clock() - begin_time) / CLOCKS_PER_SEC);

	std::sort(vec.begin(), vec.end());
	bool error = false;
	for (int i = 0; i < vec.size(); i++) {
		if (arr[i] != vec[i]) {
			std::cout << arr[i] << " ----- " << vec[i] << std::endl;
			error = true;
			break;
		}
	}
	delete[] arr;

	REQUIRE(!error);
}

TEST_CASE("Parallel std::thread array 9", "[classic]") {
	const size_t N = 4000000;

	clock_t begin_time = clock();
	int* arr = generators::generateRandomNumbersArray<int>(N, 0, 999999999);
	std::vector<int> vec(N);
	for (int i = 0; i < vec.size(); i++) {
		vec[i] = arr[i];
	}

	sort::radix_sort_tbb_arrays(arr, N, 9, 10);
	std::cout << float(clock() - begin_time) / CLOCKS_PER_SEC << std::endl;
	writeResult("Radix", "Parallel TBB", "Dynamic Array", N, 9, float(clock() - begin_time) / CLOCKS_PER_SEC);

	std::sort(vec.begin(), vec.end());
	bool error = false;
	for (int i = 0; i < vec.size(); i++) {
		if (arr[i] != vec[i]) {
			std::cout << arr[i] << " ----- " << vec[i] << std::endl;
			error = true;
			break;
		}
	}
	delete[] arr;

	REQUIRE(!error);
}
#endif // DEBUG




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

