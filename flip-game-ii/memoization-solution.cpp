class Solution {
private:
	typedef function<bool(void)> F;
public:
	/* time: O(n * 2^(n/2)), space: O(n * 2^(n/2)) */
	static bool canWin(string& s) {
		const int n = s.size();
		unordered_map<string, bool> cache;
		F backtrack = [&]() {
			if (cache.count(s))
				return cache[s];
			bool win = false;
			for (int i = 0; i < n - 1 && !win; ++i) {
				if (s[i] == '+' && s[i + 1] == '+') {
					s[i] = s[i + 1] = '-';
					if (!backtrack())
						win = true;
					s[i] = s[i + 1] = '+';
				}
			}
			return cache[s] = win;
		};
		return backtrack();
	}
};
