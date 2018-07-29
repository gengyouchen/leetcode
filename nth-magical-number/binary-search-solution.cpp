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
	template <class T>
	T gcd(T A, T B) {
		if (B)
			while ((A %= B) && (B %= A));
		return A + B;
	}
	template <class T>
	T lcm(T A, T B) {
		return A * B / gcd(A, B);
	}
public:
	int nthMagicalNumber(int N, int A, int B) {
		return findFirstTrue(1L, LONG_MAX, [&](long ans) {
			return ans / A + ans / B - ans / lcm(A, B) >= N;
		}) % 1000000007;
	}
};
