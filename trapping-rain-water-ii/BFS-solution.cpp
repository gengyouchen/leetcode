class Solution {
private:
	typedef pair<int, int> PII;
	typedef priority_queue<PII, vector<PII>, greater<PII>> MinHeap;
public:
	/* time: O(m * n * log(m * n)), space: O(m * n) */
	int trapRainWater(const vector<vector<int>>& heightMap) {
		if (heightMap.empty())
			return 0;
		const int m = heightMap.size(), n = heightMap[0].size();

		MinHeap boundary;
		vector<bool> localBitmap(m * n, true);
		auto discover = [&](int row, int col) {
			const int cell = row * n + col, h = heightMap[row][col];
			if (localBitmap[cell]) {
				localBitmap[cell] = false;
				boundary.emplace(h, cell);
			}
		};

		for (int row = 0; row < m; ++row)
			for (int col = 0; col < n; ++col)
				if ((row == 0) || (row == m - 1) || (col == 0) || (col == n - 1))
					discover(row, col);

		int globalThreshold = 0, ans = 0;
		while (!boundary.empty()) {
			const PII lowest = boundary.top();
			boundary.pop();

			const int row = lowest.second / n, col = lowest.second % n;
			if (row + 1 < m)
				discover(row + 1, col);
			if (row - 1 >= 0)
				discover(row - 1, col);
			if (col + 1 < n)
				discover(row, col + 1);
			if (col - 1 >= 0)
				discover(row, col - 1);

			const int localThreshold = lowest.first;
			globalThreshold = max(globalThreshold, localThreshold);
			ans += globalThreshold - localThreshold;
		}
		return ans;
	}
};
