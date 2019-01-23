class Solution {
public:
	/* time: O(n), space: O(size(charset)) */
	int lengthOfLongestSubstringKDistinct(const string& s, int k) {
		int nAppeared[256] = {};
		int nUnique = 0, ans = 0;
		auto L = s.begin();
		for (auto R = s.begin(); R != s.end(); ++R) {
			if (++nAppeared[*R] == 1)
				++nUnique;
			while (nUnique > k) {
				if (--nAppeared[*L++] == 0)
					--nUnique;
			}
			ans = max(ans, (int)distance(L, R + 1));
		}
		return ans;
	}
};
