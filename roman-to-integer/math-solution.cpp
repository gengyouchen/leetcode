class Solution {
public:
	/* time: O(n), space: O(1) */
	int romanToInt(const string& s) {
		int ans = 0;
		for (int i = 0; i < s.size(); ++i)
			if (s[i] == 'M')
				ans += 1000;
			else if (s[i] == 'D')
				ans += 500;
			else if (s[i] == 'C')
				ans += (i + 1 < s.size() && (s[i + 1] == 'D' || s[i + 1] == 'M')) ? -100 : 100;
			else if (s[i] == 'L')
				ans += 50;
			else if (s[i] == 'X')
				ans += (i + 1 < s.size() && (s[i + 1] == 'L' || s[i + 1] == 'C')) ? -10 : 10;
			else if (s[i] == 'V')
				ans += 5;
			else if (s[i] == 'I')
				ans += (i + 1 < s.size() && (s[i + 1] == 'V' || s[i + 1] == 'X')) ? -1 : 1;
		return ans;
	}
};
