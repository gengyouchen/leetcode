class Solution {
private:
	/* See LeetCode 231 - Power of Two */
	static bool isPowerOfTwo(int n) {
		return (n > 0) && !(n & (n - 1));
	}
public:
	/* time: O(1), space: O(1) */
	static bool isPowerOfFour(int num) {
		return isPowerOfTwo(num) && (num & 0b01010101010101010101010101010101);
	}
};
