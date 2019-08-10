class Solution {
public:
	/*
	 * time: O((log(n/k) + k^2) * n/k) ~= O(n ^ 1.5) if k ~= sqrt(n), space: O(n),
	 * where n = # of points, k = # of rows containing points,
	 * assuming n points are distributed evenly on k rows
	 */
	static int minAreaRect(const vector<vector<int>>& points) {
		unordered_map<int, vector<int>> rows;
		for (const auto& point : points)
			rows[point[0]].push_back(point[1]);
		if (rows.size() < 2)
			return 0;

		for (auto& row : rows) {
			auto& cols = row.second;
			if (cols.size() > 1)
				sort(cols.begin(), cols.end());
		}

		int ans = INT_MAX;
		for (const auto& row1 : rows) {
			const auto& cols1 = row1.second;
			const int y1 = row1.first;
			if (cols1.size() < 2)
				continue;

			for (const auto& row2 : rows) {
				const auto& cols2 = row2.second;
				const int y2 = row2.first;
				if (cols2.size() < 2)
					continue;
				if (y2 <= y1)
					continue;

				/* See LeetCode 350 - Intersection of Two Arrays II */
				const int len1 = cols1.size(), len2 = cols2.size();
				int i = 0, j = 0, last = -1;
				while (i < len1 && j < len2) {
					const int x1 = cols1[i], x2 = cols2[j];
					if (x1 < x2) {
						++i;
					} else if (x1 > x2) {
						++j;
					} else {
						if (last != -1)
							ans = min(ans, (x1 - last) * (y2 - y1));
						last = x1, ++i, ++j;
					}
				}
			}
		}
		return ans == INT_MAX ? 0 : ans;
	}
};
