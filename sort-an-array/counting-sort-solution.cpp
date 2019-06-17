class Solution {
private:
	template <class I, int K = 100001>
	static void countingSort(I first, I last) {
		array<int, K> count = {};
		for (auto it = first; it != last; ++it)
			++count[*it + 50000];
		for (int i = 0; i < count.size(); ++i) {
			while (count[i]--)
				*first++ = i - 50000;
		}
	}
public:
	/*
	 * time: O(n+k), space: O(k) auxiliary (i.e. does not count input & output itself),
	 * where k = # of possible input numbers = max(nums) - min(nums) + 1
	 */
	static vector<int> sortArray(vector<int>& nums) {
		countingSort(nums.begin(), nums.end());
		return nums;
	}
};
