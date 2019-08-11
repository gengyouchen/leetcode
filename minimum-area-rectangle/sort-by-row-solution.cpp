class Solution {
public:
	/*
	 * time: time: O(n + k * (log(k) + (n/k)^2)) ~= O(n ^ 1.5) if k ~= sqrt(n), space: O(n),
	 * where n = # of points, k = # of rows containing points,
	 * assuming n points are distributed evenly on k rows
	 */
	static int minAreaRect(const vector<vector<int>>& points) {
		const int n = points.size();
		using PII = pair<int, int>;

		unordered_map<int, vector<int>> rows;
		unordered_set<int> Y;
		unordered_multiset<int> unvisitedX; /* speed up */
		for (const auto& point : points) {
			const int y = point[0], x = point[1];
			rows[y].push_back(x), Y.insert(y), unvisitedX.insert(x);
		}
		if (Y.size() < 2)
			return 0;
		if (Y.size() == n)
			return 0;

		vector<int> sortedY(Y.begin(), Y.end());
		sort(sortedY.begin(), sortedY.end());

		auto h = [](const PII& p) { return p.first * 40001 + p.second; };
		unordered_map<PII, int, decltype(h)> line2y(n, h);

		int ans = INT_MAX;
		for (int y1 : sortedY) {
			const auto& cols = rows[y1];
			for (int x : cols)
				unvisitedX.erase(unvisitedX.find(x));
			if (cols.size() < 2)
				continue;

			for (int x0 : cols) {
				for (int x1 : cols) {
					if (x0 >= x1)
						continue;
					const PII line(x0, x1);

					const auto it = line2y.find(line);
					if (it != line2y.end()) {
						const int y0 = it->second;
						it->second = y1, ans = min(ans, (x1 - x0) * (y1 - y0));
					} else {
						if (unvisitedX.count(x1) && unvisitedX.count(x0)) /* speed up: check before insert */
							line2y.emplace(line, y1);
					}
				}
			}
		}
		return ans == INT_MAX ? 0 : ans;
	}
};
