class Solution {
public:
	/*
	 * time: O(log(abs(numerator)) + abs(denominator)), space: O(1) auxiliary (i.e. does not count output itself)
	 * because in the repeating decimal of (1/k), its repetend length is always < k
	 */
	string fractionToDecimal(int numerator, int denominator) {
		if (!numerator || !denominator)
			return "0";

		string ans;
		if ((numerator ^ denominator) < 0)
			ans.push_back('-');
		long dividend = (numerator < 0) ? -(long)numerator : numerator;
		const long divisor = (denominator < 0) ? -(long)denominator : denominator;

		/*
		 * Recall the long division method,
		 * the dividend in the next iteration will be the current remainder * 10.
		 * Our goal is to find out when the dividend will repeat.
		 *
		 * If we treat the dividend in each iteration as nodes in a linked list,
		 * this is exactly the same problem as LeetCode 142 - Linked List Cycle II
		 *
		 * By using the two pointers method, we can achieve O(1) space
		 */
		auto val = [&](long p) -> long { return p / divisor; };
		auto next = [&](long p) -> long { return (p % divisor) * 10; };
		auto detectCycle = [&](long p) -> long {
			long fast = p, slow = p;
			do {
				if (!next(fast) || !next(next(fast)))
					return 0;
				fast = next(next(fast)), slow = next(slow);
			} while (fast != slow);

			while (p != slow)
				p = next(p), slow = next(slow);
			return p;
		};

		ans += to_string(val(dividend)), dividend = next(dividend);
		if (!dividend)
			return ans;
		ans.push_back('.');

		const long cycleBegin = detectCycle(dividend);
		while (dividend != cycleBegin)
			ans.push_back('0' + val(dividend)), dividend = next(dividend);

		if (cycleBegin) {
			ans.push_back('(');
			do {
				ans.push_back('0' + val(dividend)), dividend = next(dividend);
			} while (dividend != cycleBegin);
			ans.push_back(')');
		}
		return ans;
	}
};
