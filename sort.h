#pragma once
#include <vector>
#include <list>
#include <random>
#include <ctime>
#include <algorithm>

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
	Container radix_sort_stl_containers(const Container& container, int width, int range) {
		Container out = container;
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
		return out;
	}

	template <typename Type>
	Type* radix_sort_arrays(Type* array, size_t size , int width, int range) {
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
		return out;
	}
}
