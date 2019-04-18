class Solution {
private:
	typedef function<bool(void)> F;
public:
	/*
	 * time: O(n!!), space: O(n), where n!! is the double factorial of n,
	 * see https://en.wikipedia.org/wiki/Double_factorial
	 */
	static bool canWin(string& s) {
		const int n = s.size();
		F backtrack = [&]() {
			bool win = false;
			for (int i = 0; i < n - 1 && !win; ++i) {
				if (s[i] == '+' && s[i + 1] == '+') {
					s[i] = s[i + 1] = '-';
					if (!backtrack())
						win = true;
					s[i] = s[i + 1] = '+';
				}
			}
			return win;
		};
		return backtrack();
	}
};
