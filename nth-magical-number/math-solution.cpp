class Solution {
private:
	/*
	 * time: O(log(min(a,b))), space: O(1)
	 * see CLRS textbook 31.2: Greatest common divisor
	 */
	template <class T>
	T gcd(T a, T b) {
		if (b)
			while ((a %= b) && (b %= a));
		return a + b;
	}
	/*
	 * time: O(log(min(a,b))), space: O(1)
	 * see CLRS textbook 31.2: Greatest common divisor
	 */
	template <class T>
	T lcm(T a, T b) {
		return a / gcd(a, b) * b;
	}
public:
	/* time: O(A+B), space: O(1) */
	int nthMagicalNumber(int N, int A, int B) {
		long LCM = lcm(A, B);
		long nMagicPerLCM = LCM / A + LCM / B - 1;

		long ans = (N / nMagicPerLCM) * LCM;
		long ansNextA = ans + A;
		long ansNextB = ans + B;
		long nMagic = (N / nMagicPerLCM) * nMagicPerLCM;

		while (nMagic < N)
			if (ansNextA < ansNextB) {
				ans = ansNextA;
				ansNextA += A;
				nMagic++;
			} else {
				ans = ansNextB;
				ansNextB += B;
				nMagic++;
			}

		return ans % 1000000007;
	}
};
