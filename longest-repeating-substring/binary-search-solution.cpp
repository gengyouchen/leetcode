#define MOD 1000000007

class RollingHash {
private:
	using LL = long long;
	static LL mod(LL x) {
		const LL ret = x % MOD;
		return (ret >= 0) ? ret : (ret + MOD);
	}
	LL h = 0, w = 0;
public:
	template <class I>
	RollingHash(I first, I last) {
		for (auto it = first; it != last; ++it)
			h = mod(h * 256 + *it), w = w ? mod(w * 256) : 1;
	}
	void roll(char L, char R) { h = mod((h - w * L) * 256 + R); }
	operator int() const { return h; }
};

class Solution {
private:
	template <class T, class F>
	static T lowestTrue(T low, T high, F cond) {
		while (low < high) {
			const T mid = low + (high - low) / 2;
			if (cond(mid))
				high = mid;
			else
				low = mid + 1;
		}
		return low;
	}
public:
	/* time: O(n*log(n)), space: O(n) */
	static int longestRepeatingSubstring(const string& S) {
		const int n = S.size();
		auto cond = [&](int len) {
			unordered_map<int, int> h;
			/*
			 * Use Rabin-Karp algorithm to achieve O(n) expected time
			 * See LeetCode 28 - Implement strStr()
			 */
			RollingHash curr(S.begin(), S.begin() + len);
			for (int L = 0, R = len - 1; R < n; ++L, ++R) {
				const auto it = h.find(curr);
				if (it != h.end() && !S.compare(it->second, len, S, L, len))
					return false; /* found */
				h[curr] = L;
				if (R != n - 1)
					curr.roll(S[L], S[R + 1]);
			}
			return true; /* not found */
		};
		return lowestTrue(1, n, cond) - 1;
	}
};
