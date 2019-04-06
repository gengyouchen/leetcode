class Solution {
public:
	/* time: O(n), space: O(1) auxiliary (i.e. does not count input & output itself) */
	static void moveZeroes(vector<int>& nums) {
		auto L = nums.begin();
		for (auto R = nums.begin(); R != nums.end(); ++R) {
			if (*R)
				iter_swap(L++, R);
		}
	}
};
