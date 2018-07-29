class Solution {
private:
	unsigned safeAbs(int x) {
		return (x == INT_MIN) ? (unsigned int)INT_MAX + 1 : (x < 0) ? -x : x;
	}
public:
	/* time: O(log(32-bit)), space: O(log(32-bit)) */
	int divide(int dividend, int divisor) {
		if (dividend == INT_MIN && divisor == -1)
			return INT_MAX; /* overflow */

		unsigned dvd = safeAbs(dividend);
		unsigned dvs = safeAbs(divisor);
		unsigned quo = 0;

		int dvsPlace = 0;
		for (dvsPlace = 0; !(dvs & safeAbs(INT_MIN)); ++dvsPlace, dvs <<= 1);
		for (; dvsPlace >= 0; --dvsPlace, dvs >>= 1)
			if (dvs <= dvd) {
				quo += (1 << dvsPlace),
				dvd -= dvs;
			}

		return ((dividend ^ divisor) < 0) ? -quo : quo;
	}
};
