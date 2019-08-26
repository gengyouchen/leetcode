class Solution {
private:
	static int popcount(int x) {
		int count = 0;
		while (x)
			x &= x - 1, ++count;
		return count;
	}
	static int Manhattan(const vector<int>& worker, const vector<int>& bike) {
		return abs(worker[0] - bike[0]) + abs(worker[1] - bike[1]);
	}
public:
	/* time: O(m * 2^m), space: O(2^m), where n = # of workers, m = # of bikes */
	static int assignBikes(const vector<vector<int>>& workers, const vector<vector<int>>& bikes) {
		const int n = workers.size(), m = bikes.size(), full = 1 << m;
		int ans = INT_MAX;

		vector<int> dp(full, INT_MAX);
		dp[0] = 0;
		for (int mask = 1; mask < full; ++mask) {
			const int k = popcount(mask);
			if (k > n)
				continue; /* speed up */

			for (int i = 0; i < m; ++i) {
				const int bit = 1 << i;
				if (mask & bit) {
					const int prev = mask & ~bit;
					dp[mask] = min(dp[mask], dp[prev] + Manhattan(workers[k - 1], bikes[i]));
				}
			}
			if (k == n)
				ans = min(ans, dp[mask]);
		}
		return ans;
	}
};
