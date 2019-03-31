class Solution {
public:
	/* time: O(n), space: O(|charset|), where n = s.size() */
	bool canPermutePalindrome(const string& s) {
		int h[256] = {};
		for (unsigned char c : s)
			++h[c];
		bool hasOdd = false;
		for (int c = 0; c < 256; ++c) {
			if (h[c] % 2) {
				if (hasOdd)
					return false;
				hasOdd = true;
			}
		}
		return true;
	}
};
