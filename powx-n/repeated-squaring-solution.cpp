class Solution {
public:
	/*
	 * time: O(# of bits per integer), space: O(1)
	 *
	 * The following method is called "Repeated Squaring"
	 * See the CLRS textbook 31.6: Powers of an element
	 */
	double myPow(double x, int n) {
		if (x == 0)
			return 0;
		const double base = (n > 0) ? x : (1 / x);

		auto myAbs = [](int n) -> unsigned {
			return (n == INT_MIN) ? ((unsigned)INT_MAX + 1) : abs(n);
		};
		const unsigned int exponent = myAbs(n);

		double ans = 1, curr = base;
		for (unsigned bit = 1; bit; bit <<= 1) {
			if (exponent & bit)
				ans *= curr;
			curr *= curr;
		}
		return ans;
	}
};
