#pragma once
#include <vector>
#include <list>

namespace sort{
	template <typename Container>
	Container radix_sort(const Container& container, int width, int range) {
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
}
