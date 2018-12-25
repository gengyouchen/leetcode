class Solution {
private:
	typedef string::const_iterator I;
	bool valid(I first, I last, int k) {
		while (first < last)
			if (*first == *(last - 1))
				++first, --last;
			else if (k == 0)
				return false;
			else
				return valid(first + 1, last, k - 1) || valid(first, last - 1, k - 1);
		return true;
	}
public:
	/* time: O(n), space: O(1) */
	bool validPalindrome(const string& s) {
		return valid(s.begin(), s.end(), 1);
	}
};
