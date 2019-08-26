class Counter {
private:
	int char2count[128] = {};
	int nDistinct = 0;
public:
	void add(char c) {
		if (++char2count[c] == 1)
			++nDistinct;
	};
	void remove(char c) {
		if (--char2count[c] == 0)
			--nDistinct;
	}
	int countDistinct() const { return nDistinct; }
};

class Solution {
public:
	/* time: O(n), space: O(|charset|) */
	static int lengthOfLongestSubstringKDistinct(const string& s, int k) {
		const int n = s.size();
		Counter window;
		int ans = 0, L = 0;
		for (int R = 0; R < n; ++R) {
			window.add(s[R]);
			while (window.countDistinct() > k)
				window.remove(s[L++]);
			ans = max(ans, R - L + 1);
		}
		return ans;
	}
};
