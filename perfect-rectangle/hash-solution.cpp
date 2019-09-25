class Solution {
public:
	/* time: O(n), space: O(n), where n = # of rectangles */
	static bool isRectangleCover(const vector<vector<int>>& rectangles) {
		unordered_map<int, unordered_map<int, int>> row2corners;
		int yMin = INT_MAX, yMax = INT_MIN, xMin = INT_MAX, xMax = INT_MIN;
		for (const auto& rect : rectangles) {
			const int x0 = rect[0], y0 = rect[1], x1 = rect[2], y1 = rect[3];
			yMin = min(yMin, y0), yMax = max(yMax, y1), xMin = min(xMin, x0), xMax = max(xMax, x1);
			++row2corners[y0][x0], --row2corners[y0][x1], --row2corners[y1][x0], ++row2corners[y1][x1];

			if (!row2corners[y0][x0])
				row2corners[y0].erase(x0);
			if (!row2corners[y0][x1])
				row2corners[y0].erase(x1);
			if (row2corners[y0].empty())
				row2corners.erase(y0);

			if (!row2corners[y1][x0])
				row2corners[y1].erase(x0);
			if (!row2corners[y1][x1])
				row2corners[y1].erase(x1);
			if (row2corners[y1].empty())
				row2corners.erase(y1);
		}

		return (row2corners.size() == 2) && (row2corners[yMin].size() == 2) && (row2corners[yMax].size() == 2) &&
			(row2corners[yMin][xMin] == 1) && (row2corners[yMin][xMax] == -1) &&
			(row2corners[yMax][xMin] == -1) && (row2corners[yMax][xMax] == 1);
	}
};
