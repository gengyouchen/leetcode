class Solution {
public:
	/* time: O(1), space: O(1) */
	bool isPowerOfTwo(int n) {
		if (n <= 0)
			return false;
		auto LSB = [](int x) { return x & -x; };
		return LSB(n) == n;
	}
};
