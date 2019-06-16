class Solution {
private:
	/* See CLRS textbook 9.2: Selection in expected linear time */
	template <class I, class F>
	static void quickselect(I first, I nth, I last, F comp) {
		auto pred = [&](const auto& val) { return comp(val, *(last - 1)); };
		while (last - first > 1) {
			iter_swap(first + rand() % (last - first), last - 1);
			const auto pivot = partition(first, last - 1, pred);
			iter_swap(pivot, last - 1);
			if (nth < pivot)
				last = pivot;
			else if (nth > pivot)
				first = pivot + 1;
			else
				break;
		}
	}
public:
	/* time: O(n), space: O(1) auxiliary (i.e. does not count input & output itself) */
	static int findKthLargest(vector<int>& nums, int k) {
		const auto it = nums.begin() + (k - 1);
		quickselect(nums.begin(), it, nums.end(), greater<int>());
		return *it;
	}
};
