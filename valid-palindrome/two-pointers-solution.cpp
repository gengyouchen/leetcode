class Solution {
public:
	/* time: O(n), space: O(1) */
	bool isPalindrome(const string& s) {
		if (s.empty())
			return true;
		auto L = s.begin(), R = s.end();
		while (L < R)
			if (!isalnum(*L))
				++L;
			else if (!isalnum(*(R - 1)))
				--R;
			else if (tolower(*L) == tolower(*(R - 1)))
				++L, --R;
			else
				return false;
		return true;
	}
};
