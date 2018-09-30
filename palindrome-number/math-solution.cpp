class Solution {
public:
	/* time: O(log(x)), space: O(1) */
	bool isPalindrome(int x) {
		if (x < 0)
			return false;

		int rest = x, reversed = 0;
		while (rest) {
			if (reversed > INT_MAX / 10)
				return false; /* overflow */
			reversed *= 10;

			if (reversed > INT_MAX - x % 10)
				return false; /* overflow */
			reversed += rest % 10;

			rest /= 10;
		}
		return x == reversed;
	}
};
