class Solution {
private:
	template <class I>
	static void mergeSort(I first, I last, I output) {
		if (last - first > 1) {
			const auto mid = first + (last - first) / 2;
			mergeSort(first, mid, output), mergeSort(mid, last, output);

			const auto end = merge(first, mid, mid, last, output);
			copy(output, end, first);
		}
	}
public:
	/* time: O(n*log(n)), space: O(log(n)) auxiliary (i.e. does not count input & output itself) */
	static vector<int> sortArray(vector<int>& nums) {
		const int n = nums.size();
		vector<int> ans(n);
		mergeSort(nums.begin(), nums.end(), ans.begin());
		return ans;
	}
};
