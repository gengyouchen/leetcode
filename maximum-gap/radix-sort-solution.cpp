class Solution {
public:
	/* time: O(n), space: O(n) */
	int maximumGap(vector<int>& nums) {
		const int n = nums.size();
		if (n < 2)
			return 0;

		/* Use radix sort to achieve O(n) time */
		auto digit = [](int num, int i) { return (num >> 4 * i) % 16; };
		for (int i = 0; i < 8; ++i) {
			int count[16] = {};
			for (int num : nums)
				++count[digit(num, i)];
			partial_sum(count, count + 16, count);

			vector<int> tmp(n);
			for (auto it = nums.rbegin(); it != nums.rend(); ++it)
				tmp[--count[digit(*it, i)]] = *it;
			nums = move(tmp);
		}

		int ans = 0;
		for (auto it = nums.begin() + 1; it != nums.end(); ++it)
			ans = max(ans, *it - *(it - 1));
		return ans;
	}
};
