class Solution {
public:
	/* time: O(1), space: O(1) */
	static bool isBoomerang(const vector<vector<int>>& points) {
		const int dx1 = points[1][0] - points[0][0];
		const int dy1 = points[1][1] - points[0][1];
		const int dx2 = points[2][0] - points[0][0];
		const int dy2 = points[2][1] - points[0][1];
		return dx1 * dy2 != dx2 * dy1;
	}
};
