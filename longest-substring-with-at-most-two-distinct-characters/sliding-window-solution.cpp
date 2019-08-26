/*
 * Notice that we can solve this problem without using hash table
 *
 * For hash table solution,
 * see LeetCode 340 - Longest Substring with At Most K Distinct Characters
 * where k = 2 for this problem
 */
class Counter {
private:
	char a = 0, b = 0;
	int nA = 0, nB = 0;
public:
	bool add(char c) {
		if (nA && a == c)
			++nA;
		else if (nB && b == c)
			++nB;
		else if (!nA)
			a = c, nA = 1;
		else if (!nB)
			b = c, nB = 1;
		else
			return false;
		return true;
	};
	bool remove(char c) {
		if (nA && a == c)
			--nA;
		else if (nB && b == c)
			--nB;
		else
			return false;
		return true;
	}
	bool isFull() const { return nA && nB; }
};

class Solution {
public:
	/* time: O(n), space: O(1) */
	static int lengthOfLongestSubstringTwoDistinct(const string& s) {
		const int n = s.size();
		Counter window;
		int ans = 0, L = 0;
		for (int R = 0; R < n; ++R) {
			if (!window.add(s[R])) {
				while (window.isFull())
					window.remove(s[L++]);
				window.add(s[R]);
			}
			ans = max(ans, R - L + 1);
		}
		return ans;
	}
};
