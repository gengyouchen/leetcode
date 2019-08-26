class Solution {
private:
	static int Manhattan(const vector<int>& worker, const vector<int>& bike) {
		return abs(worker[0] - bike[0]) + abs(worker[1] - bike[1]);
	}
public:
	/* time: O(m * 2^n * n), space: O(2^n), where n = # of workers, m = # of bikes */
	static int assignBikes(const vector<vector<int>>& workers, const vector<vector<int>>& bikes) {
		const int n = workers.size(), m = bikes.size(), full = 1 << n;
		vector<vector<int>> _dp(2, vector<int>(full, INT_MAX));
#define DP(i, j) _dp[(i) % 2][j]
		DP(0, 0) = 0;
		for (int i = 1; i <= m; ++i) {
			for (int mask = 0; mask < full; ++mask) {
				DP(i, mask) = DP(i - 1, mask);
				for (int j = 0; j < n; ++j) {
					const int bit = 1 << j;
					if (mask & bit) {
						const int prev = mask & ~bit;
						if (DP(i - 1, prev) != INT_MAX)
							DP(i, mask) = min(DP(i, mask), DP(i - 1, prev) + Manhattan(workers[j], bikes[i - 1]));
					}
				}
			}
		}
		return DP(m, full - 1);
#undef DP
	}
};
