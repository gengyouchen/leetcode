class RollingHash {
private:
	template <class T>
	static T mod(T x) {
		const T p = 1000000007, r = x % p;
		return (r >= 0) ? r : (r + p);
	}
	queue<char> str;
	stack<long long> w;
	long long h = 0;
public:
	void push(char c) {
		h = mod(h * 256 + c), w.push(w.empty() ? 1 : mod(w.top() * 256)), str.push(c);
	}
	void pop() {
		h = mod(h - w.top() * str.front()), w.pop(), str.pop();
	}
	void pop_and_push(char c) {
		h = mod((h - w.top() * str.front()) * 256 + c), str.pop(), str.push(c);
	}
	operator int() const {
		return h;
	}
};

class Solution {
private:
	typedef function<bool(int, int, int)> F;
public:
	/* time: O(C(n, m)), space: O(n + m), where m = |pattern|, n = |str| */
	static bool wordPatternMatch(const string& pattern, const string& str) {
		const int m = pattern.size(), n = str.size();
		unordered_map<char, int> nChar;
		for (char c : pattern)
			++nChar[c];

		/* map each char to a unique substring */
		unordered_map<char, string> c2s;

		/* map each substring to a unique char (for speed, we use rolling hash instead of actual substring) */
		unordered_map<int, unordered_set<char>> s2c;

		F backtrack = [&](int i, int j, int minStrSize) {
			if (i == m || j == n)
				return (i == m) && (j == n);

			const char c = pattern[i];
			if (c2s.count(c)) {
				const int len = c2s[c].size();
				if (str.compare(j, len, c2s[c]))
					return false;
				return backtrack(i + 1, j + len, minStrSize);
			} else {
				RollingHash h;
				for (int len = 1; j + len - 1 < n; ++len) {
					const int expectedSize = minStrSize + nChar[c] * (len - 1);
					if (expectedSize > n)
						break;

					/* increase substring size and update its rolling hash */
					c2s[c].push_back(str[j + len - 1]), h.push(str[j + len - 1]);

					/* make sure this substring is NOT already mapped by other char */
					if (s2c.count(h)) {
						bool alreadyMapped = false;
						for (char other : s2c[h]) {
							if (c2s[c] == c2s[other]) {
								alreadyMapped = true;
								break;
							}
						}
						if (alreadyMapped)
							continue;
					}

					/* do DFS recursively */
					s2c[h].insert(c);
					if (backtrack(i + 1, j + len, expectedSize))
						return true;
					s2c[h].erase(c);
					if (s2c[h].empty())
						s2c.erase(h);
				}
				c2s.erase(c);
				return false;
			}
		};
		return backtrack(0, 0, m);
	}
};
