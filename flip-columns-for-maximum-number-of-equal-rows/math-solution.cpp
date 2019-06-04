class Solution {
public:
	/* time: O(n^2), space: O(n^2) */
	static int maxEqualRowsAfterFlips(const vector<vector<int>>& matrix) {
		const int m = matrix.size(), n = matrix[0].size();
		/*
		 * Key Observation:
		 * If row[i] != row[j] initially,
		 * then no matter how many columns we've flipped, row[i] != row[j].
		 *
		 * Therefore, when row[i] becomes all values 0,
		 * (1) row[a] becomes all values 0 IFF row[i] == row[a] initially
		 * (2) row[b] becomes all values 1 IFF row[i] == ~row[b] initially
		 */
		unordered_map<string, int> h;
		int ans = 0;
		string key(n, '?'), inv(n, '?');
		for (const auto& row : matrix) {
			for (int i = 0; i < n; ++i) {
				if (row[i])
					key[i] = '1', inv[i] = '0';
				else
					key[i] = '0', inv[i] = '1';
			}
			int nEqual = ++h[key];
			const auto it = h.find(inv);
			if (it != h.end())
				nEqual += it->second;
			ans = max(ans, nEqual);
		}
		return ans;
	}
};
