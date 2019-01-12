class Solution {
public:
	/* time: O(n), space: O(1) */
	vector<int> singleNumber(const vector<int>& nums) {
		auto LSB = [](int x) { return x & -x; };
		int ansDiff = 0;
		for (int num : nums)
			ansDiff ^= num;
		const int pivot = LSB(ansDiff);

		int ans0 = 0, ans1 = 0;
		for (int num : nums) {
			if (num & pivot)
				ans1 ^= num;
			else
				ans0 ^= num;
		}
		return {ans1, ans0};
	}
};
