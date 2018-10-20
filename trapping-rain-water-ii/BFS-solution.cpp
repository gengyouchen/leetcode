class Solution {
public:
	/* time: O(m * n * log(m * n)), space: O(m * n) */
	int trapRainWater(const vector<vector<int>>& heightMap) {
		if (heightMap.empty())
			return 0;
		const int m = heightMap.size(), n = heightMap[0].size();

		set<pair<int, int>> boundary;
		vector<bool> inside(m * n, true);
		auto discover = [&](int row, int col) {
			if (row >= 0 && row < m && col >= 0 && col < n && inside[row * n + col]) {
				inside[row * n + col] = false;
				boundary.emplace(heightMap[row][col], row * n + col);
			}
		};

		for (int row = 0; row < m; ++row)
			for (int col = 0; col < n; ++col)
				if (row == 0 || row == m - 1 || col == 0 || col == n - 1)
					discover(row, col);

		int outsideTrapLevel = 0, ans = 0;
		while (!boundary.empty()) {
			auto lowest = boundary.begin();
			const int row = lowest->second / n, col = lowest->second % n;
			boundary.erase(lowest);

			outsideTrapLevel = max(outsideTrapLevel, heightMap[row][col]);
			ans += outsideTrapLevel - heightMap[row][col];

			discover(row + 1, col);
			discover(row - 1, col);
			discover(row, col + 1);
			discover(row, col - 1);
		}
		return ans;
	}
};
