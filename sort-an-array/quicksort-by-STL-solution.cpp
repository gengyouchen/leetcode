class Solution {
private:
	/* See CLRS textbook 7.3: A randomized version of quicksort */
	template <class I>
	static void quicksort(I first, I last) {
		if (last - first > 1) {
			iter_swap(first + rand() % (last - first), last - 1);
			auto pred = [&](const auto& val) { return val < *(last - 1); };
			const auto pivot = partition(first, last - 1, pred);
			iter_swap(pivot, last - 1);
			quicksort(first, pivot), quicksort(pivot + 1, last);
		}
	}
public:
	/* time: O(n*log(n)), space: O(log(n)) auxiliary (i.e. does not count input & output itself) */
	static vector<int> sortArray(vector<int>& nums) {
		quicksort(nums.begin(), nums.end());
		return nums;
	}
};
