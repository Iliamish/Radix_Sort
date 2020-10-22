#pragma once
#include <vector>
#include <list>
#include <random>
#include <ctime>
#include <algorithm>
#include <mpi.h>

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
		std::vector<int> output(vector1.size() + vector2.size() - 1);
		for (size_t i = 0; i < vector1.size() + vector2.size() - 1; i++) {
			if (vector1[A] < vector2[B]) {
				output[i] = vector1[A];
				++A;
			} else {
				output[i] = vector2[B];
				++B;
			}

			if (A == vector1.size()) {
				for (size_t j = 0; j < vector2.size() - B - 1; j++) {
					output[i + j + 1] = vector2[B + j];
				}
				break;
			}

			if (B == vector2.size()) {
				for (size_t j = 0; j < vector1.size() - A - 1; j++) {
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

	template <typename Type>
	void radix_sort_arrays(Type* array, size_t size , int width, int range) {
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
}


