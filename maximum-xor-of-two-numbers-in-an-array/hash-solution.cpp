class Solution {
public:
	/* time: O(n), space: O(n) */
	static int findMaximumXOR(const vector<int>& nums) {
		int ans = 0, mask = 0;
		for (int d = 31; d >= 0; --d) {
			mask |= (1 << d);
			const int test = ans | (1 << d);

			unordered_set<int> s;
			for (int num : nums) {
				num &= mask;
				if (s.count(num ^ test)) {
					ans = test;
					break;
				}
				s.insert(num);
			}
		}
		return ans;
	}
};
