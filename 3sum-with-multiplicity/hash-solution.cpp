class Solution {
public:
	/* time: O(n + W^2), space: O(W), where W = # of distinct numbers in A */
	static int threeSumMulti(const vector<int>& A, int target) {
		unordered_map<int, long> h;
		for (int a : A)
			++h[a];
		long ans = 0;
		for (auto x : h) {
			for (auto y : h) {
				const int i = x.first, j = y.first, k = target - i - j;
				if (h.count(k) && i <= j && j <= k) {
					if (i == j && j == k) /* has C(h[i], 3) tuples */
						ans += h[i] * (h[i] - 1) * (h[i] - 2) / 6;
					else if (i == j) /* has C(h[i], 2) * h[k] tuples */
						ans += (h[i] * (h[i] - 1) / 2) * h[k];
					else if (j == k) /* has h[i] * C(h[j], 2) tuples */
						ans += h[i] * (h[j] * (h[j] - 1) / 2);
					else /* has h[i] * h[j] * h[k] tuples */
						ans += h[i] * h[j] * h[k];
					ans %= 1000000007;
				}
			}
		}
		return ans;
	}
};
