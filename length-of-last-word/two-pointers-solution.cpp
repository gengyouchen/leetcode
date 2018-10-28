class Solution {
public:
	/* time: O(n), space: O(1) */
	int lengthOfLastWord(const string& s) {
		auto L = s.end(), R = s.end();
		for (auto it = s.begin(); it != s.end(); ++it)
			if (*it != ' ')
				if (it == s.begin() || *(it - 1) == ' ')
					L = it, R = it + 1;
				else
					R = it + 1;
		return distance(L, R);
	}
};
