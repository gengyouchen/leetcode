class Solution {
public:
	/*
	 * time: O(n*log(log(n))), space: O(n)
	 * because sum { n/p for 1<=p<=n } is O(n*log(log(n))) using Mertens' second theorem
	 * See https://en.wikipedia.org/wiki/Mertens%27_theorems
	 */
	int countPrimes(int n) {
		vector<char> isPrime(n, 1);
		for (int i = 0; (i * i) < n; ++i) {
			if (i < 2) {
				isPrime[i] = 0;
			} else if (isPrime[i]) {
				for (int j = (i * i); j < n; j += i)
					isPrime[j] = 0;
			}
		}
		return count(isPrime.begin(), isPrime.end(), 1);
	}
};
