class Solution {
public:
	/* time: O(m) = O(n), space: O(1), where m = len(s), n = len(t) */
	bool isOneEditDistance(const string& s, const string& t) {
		/*
		 * This is the easier version of LeetCode 72 - Edit Distance
		 *
		 * Because we only allow distance <= 1, we don't need to use DP.
		 * Just do a linear scan to check.
		 */
		const int m = s.size(), n = t.size();
		if (m > n)
			return isOneEditDistance(t, s);
		if (n - m > 1)
			return false;

		bool edited = false;
		auto L = s.begin();
		for (auto R = t.begin(); R != t.end(); ++R) {
			if (*R != *L) {
				if (edited)
					return false;
				edited = true;
			}
			if (*R == *L || n == m)
				++L;
		}
		return edited;
	}
};
