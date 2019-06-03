class Solution {
private:
	/*
	 * time: O(log(min(a,b))), space: O(1)
	 * see CLRS textbook 31.2: Greatest common divisor
	 */
	static int gcd(int a, int b) {
		if (b)
			while ((a %= b) && (b %= a));
		return a + b;
	}
public:
	/* time: O(m+n), space: O(1) auxiliary (i.e. does not count output itself) */
	static string gcdOfStrings(const string& str1, const string& str2) {
		if (str1.empty() || str2.empty())
			return "";
		const int m = str1.size(), n = str2.size(), k = gcd(m, n);
		for (int i = 0; i < k; ++i) {
			if (str1[i] != str2[i])
				return "";
		}
		for (int i = k; i < m; ++i) {
			if (str1[i] != str1[i % k])
				return "";
		}
		for (int i = k; i < n; ++i) {
			if (str2[i] != str2[i % k])
				return "";
		}
		return str1.substr(0, k);
	}
};
