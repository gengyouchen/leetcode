class Counter {
private:
	const int threshold;
	int char2count[26] = {};
	int nDistinct = 0, nDistinctOverThreshold = 0;
public:
	Counter(int threshold) : threshold(max(threshold, 1)) {}
	void add(char c) {
		const int after = ++char2count[c - 'a'];
		if (after == 1)
			++nDistinct;
		if (after == threshold)
			++nDistinctOverThreshold;
	};
	void remove(char c) {
		const int after = --char2count[c - 'a'];
		if (after == 0)
			--nDistinct;
		if (after == threshold - 1)
			--nDistinctOverThreshold;
	}
	int countDistinct() const { return nDistinct; }
	int countDistinctOverThreshold() const { return nDistinctOverThreshold; }
};

class Solution {
private:
	/* See LeetCode 340 - Longest Substring with At Most K Distinct Characters */
	static int lengthOfLongestSubstringKDistinct(const string& s, int k, int threshold) {
		const int n = s.size();
		Counter window(threshold);
		int ans = 0, L = 0;
		for (int R = 0; R < n; ++R) {
			window.add(s[R]);
			while (window.countDistinct() > k)
				window.remove(s[L++]);
			if (window.countDistinct() == window.countDistinctOverThreshold())
				ans = max(ans, R - L + 1);
		}
		return ans;
	}
public:
	/* time: O(n * |charset|), space: O(|charset|) */
	static int longestSubstring(const string& s, int k) {
		int ans = 0;
		for (int i = 1; i <= 26; ++i)
			ans = max(ans, lengthOfLongestSubstringKDistinct(s, i, k));
		return ans;
	}
};
