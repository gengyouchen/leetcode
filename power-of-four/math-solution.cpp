class Solution {
private:
	/* See LeetCode 231 - Power of Two */
	static bool isPowerOfTwo(int n) {
		return (n > 0) && !(n & (n - 1));
	}
public:
	/*
	 * time: O(1), space: O(1)
	 *
	 * How to distinguish 4 ^ n from 2 ^ n?
	 * Answer: check if x % 3 == 1
	 *
	 * <Proof>
	 * Let x = 2 ^ n = (3 - 1) ^ n
	 *
	 * If n is even,
	 * then x's binomial expansion = 3 * (...) + (-1) ^ n = 3 * k + 1
	 *
	 * If n is odd,
	 * then x's binomial expansion = 3 * (...) + (-1) ^ n = 3 * k - 1
	 */
	static bool isPowerOfFour(int num) {
		return isPowerOfTwo(num) && (num % 3 == 1);
	}
};
