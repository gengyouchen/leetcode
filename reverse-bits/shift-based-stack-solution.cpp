class Solution {
public:
	/* time: O(1), space: O(1) */
	uint32_t reverseBits(uint32_t n) {
		uint32_t ans = 0;
		for (int i = 0; i < 32; ++i) {
			ans <<= 1, ans |= n & 1; /* ans.push(n.top()) */
			n >>= 1; /* n.pop() */
		}
		return ans;
	}
};
