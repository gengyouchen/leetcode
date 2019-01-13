class Solution {
public:
	/* time: O(n), space: O(1) auxiliary (i.e. does not count input & output itself) */
	void rotate(vector<int>& nums, int k) {
		const int n = nums.size();
		k %= n;
		int start = 0;
		for (int nSwap = 0; nSwap < n;) {
			int i = start, bak = nums[start];
			do {
				i = (i + k) % n;
				swap(nums[i], bak), ++nSwap;
			} while (i != start);
			++start;
		}
	}
};
