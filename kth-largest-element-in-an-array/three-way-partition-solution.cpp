class Solution {
private:
	enum Color { RED = 0, WHITE = 1, BLUE = 2 };
	template <class I>
	auto partition3(I first, I last) {
		auto pivot = *(first + rand() % (last - first));
		auto color = [&](auto it) { return (*it > pivot) ? RED : (*it == pivot) ? WHITE : BLUE; };
		/*
		 * This is exactly the Dutch National Flag (DNF) problem by Edsger Dijkstra
		 * See LeetCode 75 - Sort Colors
		 */
		auto lastRed = first, it = lastRed, firstBlue = last;
		while (it != firstBlue)
			if (color(it) == RED)
				iter_swap(it++, lastRed++);
			else if (color(it) == BLUE)
				iter_swap(it, --firstBlue);
			else
				++it;
		return make_pair(lastRed, firstBlue);
	}
public:
	/* time: O(n), space: O(1) auxiliary (i.e. does not count input & output itself) */
	int findKthLargest(vector<int>& nums, int k) {
		auto first = nums.begin(), last = nums.end();
		auto target = nums.begin() + (k - 1);
		while (last - first > 1) {
			auto it = partition3(first, last);
			if (target < it.first)
				last = it.first;
			else if (target >= it.second)
				first = it.second;
			else /* found */
				first = it.first, last = first + 1;
		}
		return *first;
	}
};
