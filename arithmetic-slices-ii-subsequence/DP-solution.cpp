class Solution {
public:
	/* time: O(n^2), space: O(n^2) */
	static int numberOfArithmeticSlices(const vector<int>& A) {
		const int n = A.size();

		vector<unordered_map<long long, int>> dp(n);
		unordered_multiset<long long> unvisited(A.begin(), A.end()); /* speed up */

		int ans = 0;
		for (int i = 0; i < n; ++i) {
			const long long curr = A[i];
			unvisited.erase(unvisited.find(curr));

			for (int j = 0; j < i; ++j) {
				const long long prev = A[j], delta = curr - prev, next = curr + delta;

				int count = 1;
				const auto it = dp[j].find(delta);
				if (it != dp[j].end())
					count += it->second;
				if (unvisited.find(next) != unvisited.end()) /* speed up: check before insert */
					dp[i][delta] += count;

				ans += count - 1; /* only count sequence with length >= 3, not 2 */
			}
		}
		return ans;
	}
};
