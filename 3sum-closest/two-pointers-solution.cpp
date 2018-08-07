class Solution {
private:
	template <class I, class T, class F>
	void sortedTwoSumClosest(I first, I last, T target, F found) {
		I ans[2];
		T d = numeric_limits<T>::max();
		while (last - first > 1) {
			T sum = *first + *(last - 1);
			if (abs(sum - target) < d)
				d = abs(sum - target), ans[0] = first, ans[1] = last - 1;
			if (sum < target)
				++first;
			else if (sum > target)
				--last;
			else
				break;
		}
		if (d < numeric_limits<T>::max())
			found(ans[0], ans[1]);
	}
public:
	/* time: O(n^2), space: O(1) auxiliary (i.e. does not count input itself) */
	int threeSumClosest(vector<int>& nums, int target) {
		make_heap(nums.begin(), nums.end());
		sort_heap(nums.begin(), nums.end());
		int ans, d = INT_MAX;
		for (auto z = nums.begin(); z != nums.end(); ++z) {
			int complement = target - *z;
			sortedTwoSumClosest(nums.begin(), z, complement, [&](auto x, auto y) {
				int sum = *x + *y + *z;
				if (abs(sum - target) < d)
					d = abs(sum - target), ans = sum;
			});
		}
		return ans;
	}
};
