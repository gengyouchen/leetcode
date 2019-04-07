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
	RollingHash(const string& s) {
		for (char c : s)
			push(c);
	}
	void push(char c) {
		h = mod(h * 256 + c), w.push(w.empty() ? 1 : mod(w.top() * 256)), str.push(c);
	}
	void pop() {
		h = mod(h - w.top() * str.front()), w.pop(), str.pop();
	}
	void pop_and_push(char c) {
		h = mod((h - w.top() * str.front()) * 256 + c), str.pop(), str.push(c);
	}
	int hash() const {
		return h;
	}
};

class Solution {
public:
	/* time: O(n + m), space: O(m), where n = |haystack|, m = |needle| */
	static int strStr(const string& haystack, const string& needle) {
		const int n = haystack.size(), m = needle.size(), goal = RollingHash(needle).hash();
		RollingHash curr(haystack.substr(0, m));

		for (int L = 0, R = m - 1; R < n; ++L, ++R) {
			if (curr.hash() == goal && haystack.substr(L, m) == needle)
				return L; /* found */

			if (R != n - 1)
				curr.pop_and_push(haystack[R + 1]);
		}
		return -1; /* not found */
	}
};
