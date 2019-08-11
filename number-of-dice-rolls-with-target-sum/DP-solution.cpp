#define MOD 1000000007

class Solution {
private:
	using LL = long long;
	static LL mod(LL x) {
		const LL r = x % MOD;
		return (r >= 0) ? r : (r + MOD);
	};
public:
	/* time: O(d * f * target), space: O(target) */
	static int numRollsToTarget(int d, int f, int target) {
		vector<vector<LL>> _dp(2, vector<LL>(target + 1));

#define DP(i, j) _dp[(i) % 2][j]
		for (int i = 1; i <= d; ++i) {
			for (int j = 1; j <= target; ++j) {
				if (i == 1) {
					DP(i, j) = (j <= f) ? 1 : 0;
				} else {
					DP(i, j) = 0;
					for (int k = 1; k <= f; ++k) {
						if (j - k > 0)
							DP(i, j) = mod(DP(i, j) + DP(i - 1, j - k));
					}
				}
			}
		}
		return DP(d, target);
#undef DP
	}
};
