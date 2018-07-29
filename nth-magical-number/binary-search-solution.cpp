class Solution {
private:
	template <class I, class F>
	I findFirstTrue(I first, I last, F cond) {
		while (first != last) {
			I mid = first + (last - first) / 2;
			if (cond(mid))
				last = mid;
			else
				first = mid + 1;
		}
		return first;
	}
	/*
	 * time: O(log(min(A,B))), space: O(1)
	 * see CLRS textbook 31.2: Greatest common divisor
	 */
	template <class T>
	T gcd(T A, T B) {
		if (B)
			while ((A %= B) && (B %= A));
		return A + B;
	}
	/*
	 * time: O(log(min(A,B))), space: O(1)
	 * see CLRS textbook 31.2: Greatest common divisor
	 */
	template <class T>
	T lcm(T A, T B) {
		return A / gcd(A, B) * B;
	}
public:
	/* time: O(log(LONG_MAX)), space: O(1) */
	int nthMagicalNumber(int N, int A, int B) {
		long common = lcm(A, B);
		return findFirstTrue(1L, LONG_MAX, [&](long ans) {
			return (ans / A + ans / B - ans / common) >= N;
		}) % 1000000007;
	}
};
