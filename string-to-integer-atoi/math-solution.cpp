class Solution {
public:
	/* time: O(n), space: O(1) */
	int myAtoi(const string& str) {
		auto it = find_if(str.begin(), str.end(), [](char c) {
			return c != ' ';
		});
		if (it == str.end())
			return 0;

		bool negative = false;
		if (*it == '+')
			++it, negative = false;
		else if (*it == '-')
			++it, negative = true;

		int ans = 0;
		while (it != str.end() && isdigit(*it)) {
			int x = *it++ - '0';
			if (negative)
				x = -x;

			if (ans > INT_MAX / 10)
				return INT_MAX; /* overflow */
			if (ans < INT_MIN / 10)
				return INT_MIN; /* underflow */
			ans *= 10;

			if (x > 0 && ans > INT_MAX - x % 10)
				return INT_MAX; /* overflow */
			if (x < 0 && ans < INT_MIN - x % 10)
				return INT_MIN; /* underflow */
			ans += x % 10;

			x /= 10;
		}
		return ans;
	}
};
