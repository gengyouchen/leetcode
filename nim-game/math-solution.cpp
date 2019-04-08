class Solution {
public:
	/* time: O(1), space: O(1) */
	static bool canWinNim(int n) {
		return n % 4 != 0;
	}
};
