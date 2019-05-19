class Solution {
private:
	template <class T, class F>
	static T lowestTrue(T min, T max, F cond) {
		while (min < max) {
			const auto it = min + (max - min) / 2;
			if (cond(it) == true)
				max = it;
			else
				min = it + 1;
		}
		return min;
	}
public:
	/* time: O(n*log(m) + m*log(n)), space: O(1) */
	static int minArea(const vector<vector<char>>& image, int x, int y) {
		const int m = image.size(), n = image[0].size();
		auto isBlackX = [&](int x) {
			for (int y = 0; y < n; ++y) {
				if (image[x][y] == '1')
					return true;
			}
			return false;
		};
		auto isBlackY = [&](int y) {
			for (int x = 0; x < m; ++x) {
				if (image[x][y] == '1')
					return true;
			}
			return false;
		};
		auto isWhiteX = [&](int x) { return !isBlackX(x); };
		auto isWhiteY = [&](int y) { return !isBlackY(y); };

		const int x0 = lowestTrue(0, x, isBlackX), x1 = lowestTrue(x, m, isWhiteX);
		const int y0 = lowestTrue(0, y, isBlackY), y1 = lowestTrue(y, n, isWhiteY);
		return (x1 - x0) * (y1 - y0);
	}
};
