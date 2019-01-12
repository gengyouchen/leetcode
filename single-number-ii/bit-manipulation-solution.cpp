class Solution {
public:
	/* time: O(n), space: O(1) */
	int singleNumber(const vector<int>& nums) {
		int appear1 = 0, appear2 = 0;
		for (int num : nums) {
			/*
			 * For each bit k in current num:
			 * If num[k] is 1,
			 *     {appear2[k], appear1[k]} follows {0, 0} -> {0, 1} -> {1, 0} -> {0, 0} -> ...
			 * If num[k] is 0,
			 *     {appear2[k], appear1[k]} remains unchanged.
			 */
			const int nextAppear1 = ~appear2 & ~appear1;
			const int nextAppear2 = ~appear2 & appear1;
			appear1 = (nextAppear1 & num) | (appear1 & ~num);
			appear2 = (nextAppear2 & num) | (appear2 & ~num);
		}
		return appear1;
	}
};
