class Solution {
public:
	/* time: O(n), space: O(1) */
	static void moveZeroes(vector<int>& nums) {
		auto L = nums.begin();
		for (auto R = nums.begin(); R != nums.end(); ++R) {
			if (*R)
				iter_swap(L++, R);
		}
	}
};
