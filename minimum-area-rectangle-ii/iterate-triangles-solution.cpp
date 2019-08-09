class Solution {
private:
	using LL = long long;
	using Point = complex<LL>;
public:
	/* time: O(n^3), space: O(n), assuming sqrt(x) is O(1) time */
	static double minAreaFreeRect(const vector<vector<int>>& points) {
		const int n = points.size();
		auto h = [](const Point& p) { return p.real() * 40001 + p.imag(); };
		unordered_set<Point, decltype(h)> S(n, h);

		for (const auto& point : points)
			S.emplace(point[0], point[1]);

		double ans = DBL_MAX;
		for (const auto& a : S) {
			for (const auto& b : S) {
				if (b == a)
					continue;
				const auto v0 = b - a;
				for (const auto& c : S) {
					if (c == b)
						continue;
					const auto v1 = c - b, d = a + v1;
					if (!S.count(d))
						continue;
					if (v0.real() * v1.real() + v0.imag() * v1.imag())
						continue;
					ans = min(ans, sqrt(norm(v0) * norm(v1)));
				}
			}
		}
		return (ans == DBL_MAX) ? 0 : ans;
	}
};
