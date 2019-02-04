class Solution {
public:
	/* time: O(1), space: O(1) */
	int hammingWeight(uint32_t n) {
		int ans = 0;
		while (n)
			++ans, n &= (n - 1); /* remove lowest 1 */
		return ans;
	}
};
