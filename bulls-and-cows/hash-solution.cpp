class Solution {
public:
	/* time: O(n), space: O(1) */
	static string getHint(const string& secret, const string& guess) {
		const int n = secret.size();
		int a = 0, b = 0, S[10] = {}, G[10] = {};
		for (int i = 0; i < n; ++i) {
			const int s = secret[i] - '0', g = guess[i] - '0';
			if (s == g) {
				++a;
			} else {
				if (G[s] > 0)
					--G[s], ++b;
				else
					++S[s];
				if (S[g] > 0)
					--S[g], ++b;
				else
					++G[g];
			}
		}
		return to_string(a) + 'A' + to_string(b) + 'B';
	}
};
