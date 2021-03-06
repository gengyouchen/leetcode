class Solution {
public:
	/* time: O(log(x)), space: O(1) */
	int reverse(int x) {
		int ans = 0;
		while (x) {
			if (ans > INT_MAX / 10)
				return 0; /* overflow */
			if (ans < INT_MIN / 10)
				return 0; /* underflow */
			ans *= 10;

			if (x > 0 && ans > INT_MAX - x % 10)
				return 0; /* overflow */
			if (x < 0 && ans < INT_MIN - x % 10)
				return 0; /* underflow */
			ans += x % 10;

			x /= 10;
		}
		return ans;
	}
};
