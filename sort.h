#pragma once
#include <vector>
#include <list>
#include <random>
#include <ctime>
#include <algorithm>
#include <iterator>
#include <mpi.h>
#include <tbb/tbb.h>


namespace generators{
	template <typename Type>
	Type generateRandomNumbersContainer(size_t size, int min, int max) {
		std::mt19937 gen;
		gen.seed(static_cast<unsigned int>(time(0)));
		Type container;
		for (size_t i = 0; i < size; i++) {
			container.push_back(gen() % max + min);
		}
		return container;
	}

	template <typename Type>
	Type* generateRandomNumbersArray(size_t size, int min, int max) {
		std::mt19937 gen;
		gen.seed(static_cast<unsigned int>(time(0)));
		Type* dyn_array = new Type [size];
		for (size_t i = 0; i < size; i++) {
			dyn_array[i] = gen() % max + min;
		}
		return dyn_array;
	}
}

namespace algorithm {
	std::vector<int> merge(std::vector<int> vector1, std::vector<int> vector2) {

		/*for (size_t i = 0; i < vector1.size(); i++) {
			std::cout << vector1[i] << std::endl;
		}

		for (size_t i = 0; i < vector2.size(); i++) {
			std::cout << vector2[i] << std::endl;
		}*/

		int A = 0, B = 0;
		std::vector<int> output(vector1.size() + vector2.size());
		for (size_t i = 0; i < vector1.size() + vector2.size(); i++) {
			if (vector1[A] < vector2[B]) {
				output[i] = vector1[A];
				++A;
			} else {
				output[i] = vector2[B];
				++B;
			}

			if (A == vector1.size()) {
				for (size_t j = 0; j < vector2.size() - B; j++) {
					output[i + j + 1] = vector2[B + j];
				}
				break;
			}

			if (B == vector2.size()) {
				for (size_t j = 0; j < vector1.size() - A; j++) {
					output[i + j + 1] = vector1[A + j];
				}
				break;
			}

		}
		return output;
	}

	int* merge(int* vector1, int* vector2, size_t s1, size_t s2) {

		for (size_t i = 0; i < s1; i++) {
			std::cout << vector1[i] << std::endl;
		}

		for (size_t i = 0; i < s2; i++) {
			std::cout << vector2[i] << std::endl;
		}

		int A = 0, B = 0;
		int* output = new int[s1 + s2];
		for (size_t i = 0; i < s1 + s2; i++) {
			if (vector1[A] < vector2[B]) {
				output[i] = vector1[A];
				++A;
			} else {
				output[i] = vector2[B];
				++B;
			}

			if (A == s1) {
				for (size_t j = 0; j < s2 - B - 1; j++) {
					output[i + j + 1] = vector2[B + j];
				}
				break;
			}

			if (B == s2) {
				for (size_t j = 0; j < s1 - A - 1; j++) {
					output[i + j + 1] = vector1[A + j];
				}
				break;
			}

		}
		return output;
	}
}

namespace sort{
	template<typename Type>
	struct Node{
		Node* next = nullptr;
		Node* previous = nullptr;
		Type data;
	};

	template<typename Type>
	struct Pair {
		Type* array = nullptr;
		size_t size = 0;
	};
	
	template<typename Type>
	class List{
	public:
		size_t count = 0;
		Node<Type>* first = nullptr;
		Node<Type>* last = nullptr;

		void push_back(Type data) {
			Node<Type>* new_node = new  Node<Type>();
			new_node->data = data;
			Node<Type>* node = last;
			new_node->next = nullptr;
			if (last == nullptr) {
				first = new_node;
				last = new_node;
				last->previous = new_node;
			} else {
				last->next = new_node;
				new_node->previous = last;
				last = new_node;
			}
			++count;
		}

		void clear() {
			Node<Type>* node = first;
			while (node != nullptr) {
				Node<Type>* current_node = node;
				node = node->next;
				delete current_node;
			}
			first = nullptr;
			last = nullptr;
			count = 0;
		}
	};

	template <typename Container>
	void radix_sort_stl_containers(Container& container, int width, int range) {
		Container& out = container;
		std::vector<std::list<int>> pocketArray(range);
		int digit;
		int power = range;
		for (int k = 0; k < width; k++) {
			for (auto it = out.begin(); it < out.end(); ++it) {
				digit = *it % power / (power / range);
				pocketArray[digit].push_back(*it);
			}
			power *= range;

			out.clear();

			for (auto it = pocketArray.begin(); it < pocketArray.end(); ++it) {
				for (auto item = it->begin(); item != it->end(); ++item) {
					out.push_back(*item);
				}
				it->clear();
			}
		}
	}

	template <typename Container>
	void radix_sort_stl_containers(typename Container::iterator begin, typename Container::iterator end, int width, int range) {
		std::vector<std::list<int>> pocketArray(range);
		int digit;
		int power = range;
		for (int k = 0; k < width; k++) {
			for (auto it = begin; it < end; ++it) {
				digit = *it % power / (power / range);
				pocketArray[digit].push_back(*it);
			}
			power *= range;

			int i = 0;
			for (auto it = pocketArray.begin(); it < pocketArray.end(); ++it) {
				for (auto item = it->begin(); item != it->end(); ++item) {
					*(begin + i) = *item;
					++i;
				}
				it->clear();
			}
		}
	}

	//template <typename Container>
	void radix_sort_tbb_stl_containers(std::vector<int>& container, int width, int range) {
		container = tbb::parallel_deterministic_reduce(tbb::blocked_range<int>(0, container.size()), std::vector<int>(),
			[&](const tbb::blocked_range<int>& r, std::vector<int> v) -> std::vector<int> {
			for (int i = r.begin(); i != r.end(); ++i) {
				v.push_back(container[i]);
			}
			radix_sort_stl_containers(v, width, range);
			return v;
		},
			[](std::vector<int> v1, std::vector<int> v2) -> std::vector<int> {
			return algorithm::merge(v1, v2);
		}
		);
	}

	template <typename Type>
	void radix_sort_arrays(Type* array, size_t size, int width, int range) {
		Type* out = array;

		List<int>* pocketArray = new List<int>[range];
		int digit;
		int power = range;
		for (int k = 0; k < width; k++) {
			for (size_t i = 0; i < size; ++i) {
				digit = out[i] % power / (power / range);
				pocketArray[digit].push_back(out[i]);
			}
			power *= range;

			int pos = 0;
			for (size_t i = 0; i < range; ++i) {
				auto item = pocketArray[i].first;
				for (size_t j = 0; j < pocketArray[i].count; ++j) {
					out[pos] = item->data;
					++pos;
					item = item->next;
				}
				pocketArray[i].clear();
			}
		}
	}

	template <typename Type>
	void radix_sort_tbb_arrays(Type* array, size_t size, int width, int range) {
		for (size_t i = 0; i < size; i++) {
			std::cout << array[i] << std::endl;
		}

		Pair<Type> pair = tbb::parallel_deterministic_reduce(tbb::blocked_range<int>(0, size), Pair<Type>(),
			[&](const tbb::blocked_range<int>& r, Pair<Type> part_pair) -> Pair<Type> {
			part_pair.array = new Type[r.size()];
			part_pair.size = r.size();
			int k = 0;
			
			//std::cout <<"-------pack-----------" << r.begin() << std::endl;
			for (int i = r.begin(); i != r.end(); ++i)
				part_pair.array[k++] = array[i];
			radix_sort_arrays<Type>(part_pair.array, part_pair.size, width, range);

			/*for (int i = r.begin(); i != r.end(); ++i) {
				std::cout << part_pair.first[i] << std::endl;
			}
			std::cout <<"-------pack-----------" << r.size() << std::endl;*/

			return part_pair;
		},
			[](Pair<Type> pair1, Pair<Type> pair2) -> Pair<Type> {
				std::cout << "-------pack-----------" << pair1.size << std::endl;
				Pair<Type> ret_pair;
				ret_pair.array = algorithm::merge(pair1.array, pair2.array, pair1.size, pair2.size);
				ret_pair.size = pair1.size + pair2.size;
				delete[] pair1.array;
				delete[] pair2.array;
				return ret_pair;
			}
		);
		
		array = pair.array;
		for (size_t i = 0; i < size; i++) {
			std::cout << array[i] << std::endl;
		}

	}

	template <typename Container>
	void radix_sort_mpi_stl_containers(const Container& container, int width, int range) {
		MPI_Init(NULL, NULL);

		int size, rank;
		MPI_Comm_size(MPI_COMM_WORLD, &size);
		MPI_Comm_rank(MPI_COMM_WORLD, &rank);

		int n = container.size();
		int k;
		MPI_Bcast(&n, 1, MPI_INT, 0, MPI_COMM_WORLD);

		if (rank < n % size)
			k = n / size + 1;
		else
			k = n / size;


		int* raz = new int[size];
		int* dist = new int[size];

		if (rank == 0) {			
			int dif = 0;
			for (size_t i = 0; i < size; i++) {
				raz[i] = (rank < n% size) ? (n / size + 1) : (n / size);
				dist[i] = dif;
				dif += (rank < n% size) ? (n / size + 1) : (n / size);
			}
		}

		Container x(k);


		MPI_Scatterv(&container[0], raz, dist, MPI_INT, &x[0] , k, MPI_INT,	0, MPI_COMM_WORLD);


		radix_sort_stl_containers(x, 5, 10);

		int s = size, m = 1;

		while (s > 1)
		{
			s = s / 2 + s % 2;

			if ((rank - m) % (2 * m) == 0)

			{

				MPI_Send(&k, 1, MPI_INT,

					rank - m, 0, MPI_COMM_WORLD);

				MPI_Send(&x[0], k, MPI_INT,

					rank - m, 0, MPI_COMM_WORLD);

			}

			if ((rank % (2 * m) == 0) && (size - rank > m))

			{

				MPI_Status status;

				int k1;

				MPI_Recv(&k1, 1, MPI_INT,

					rank + m, MPI_ANY_TAG, MPI_COMM_WORLD, &status);

				Container y(k1);

				MPI_Recv(&y[0], k1, MPI_INT,

					rank + m, MPI_ANY_TAG, MPI_COMM_WORLD, &status);

				x = algorithm::merge(y, x);

				k = k + k1;

			}

			m = 2 * m;

		}

		MPI_Finalize();
	}
}


