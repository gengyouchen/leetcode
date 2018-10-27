class Solution {
public:
	/* time: O(R*C), space: O(1) (i.e. does not count output itself) */
	vector<vector<int>> spiralMatrixIII(int R, int C, int r0, int c0) {
		vector<vector<int>> ans;
		int len = 1;
		while (ans.size() < R * C) {
			if (r0 >= 0 && r0 < R)
				for (int i = max(c0, 0); i < min(c0 + len, C); ++i)
					ans.push_back({r0, i});
			c0 += len;
			if (c0 >= 0 && c0 < C)
				for (int i = max(r0, 0); i < min(r0 + len, R); ++i)
					ans.push_back({i, c0});
			r0 += len++;
			if (r0 >= 0 && r0 < R)
				for (int i = min(c0, C - 1); i > max(c0 - len, -1); --i)
					ans.push_back({r0, i});
			c0 -= len;
			if (c0 >= 0 && c0 < C)
				for (int i = min(r0, R - 1); i > max(r0 - len, -1); --i)
					ans.push_back({i, c0});
			r0 -= len++;
		}
		return ans;
	}
};
