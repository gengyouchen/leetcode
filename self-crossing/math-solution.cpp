class Solution {
public:
	/* time: O(n), space: O(1) */
	static bool isSelfCrossing(const vector<int>& x) {
		const int n = x.size();
		for (int i = 3; i < n; ++i) {
			const int a = x[i], b = x[i - 1], c = x[i - 2], d = x[i - 3];

			if (c <= a && d >= b)
				return true; /* line d will cross line a */

			if (c > a && d == b && i >= 4) {
				const int e = x[i - 4];
				if (e >= c - a)
					return true; /* line e will cross line a */
			}

			if (c > a && d > b && i >= 5) {
				const int e = x[i - 4], f = x[i - 5];
				if (e >= c - a && e <= c && f >= d - b)
					return true; /* line f will cross line a */
			}
		}
		return false;
	}
};
