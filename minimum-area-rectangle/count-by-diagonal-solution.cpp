class Solution {
public:
	/* time: O(n^2), space: O(n) */
	static int minAreaRect(const vector<vector<int>>& points) {
		const int n = points.size();

		using Point = complex<int>;
		auto h = [](const Point& p) { return p.real() * 40001 + p.imag(); };
		unordered_set<Point, decltype(h)> S(n, h);

		for (const auto& point : points)
			S.emplace(point[0], point[1]);

		int ans = INT_MAX;
		for (const auto& a : S) {
			for (const auto& b : S) {
				if (b.real() <= a.real())
					continue;
				if (b.imag() <= a.imag())
					continue;

				const Point c(a.real(), b.imag()), d(b.real(), a.imag());
				if (!S.count(c) || !S.count(d))
					continue;

				const Point diagonal = b - a;
				ans = min(ans, diagonal.real() * diagonal.imag());
			}
		}
		return ans == INT_MAX ? 0 : ans;
	}
};
