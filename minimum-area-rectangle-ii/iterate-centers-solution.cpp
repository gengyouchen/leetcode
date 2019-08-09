class Solution {
private:
	using LL = long long;
	using Point = complex<LL>;
	struct Line {
		Point center, delta;
		LL len;
		Line(const Point& a, const Point& b) : center(a + b), delta(a - b), len(norm(delta)) {
			/* make sure the delta's angle is between [0, 180) degree */
			if (delta.imag() < 0 || delta.imag() == 0 && delta.real() < 0)
				delta = -delta;
		}
	};
	static double areaRectDiagonal(const Line& a, const Line& b) {
		const double w = norm(a.delta - b.delta) / 4.0, h = a.len - w;
		return sqrt(w * h);
	}
public:
	/* time: O(n^2 * log(n)), space: O(n^2), assuming sqrt(x) is O(1) time */
	static double minAreaFreeRect(const vector<vector<int>>& points) {
		const int n = points.size();
		vector<Line> diagonals;
		for (int i = 0; i < n; ++i) {
			for (int j = i + 1; j < n; ++j) {
				Point a(points[i][0], points[i][1]), b(points[j][0], points[j][1]);
				diagonals.emplace_back(a, b);
			}
		}

		auto comp = [](const Line& a, const Line& b) {
			if (a.center.real() != b.center.real())
				return a.center.real() < b.center.real();
			if (a.center.imag() != b.center.imag())
				return a.center.imag() < b.center.imag();
			if (a.len != b.len)
				return a.len < b.len;
			return a.delta.real() < b.delta.real();
		};
		sort(diagonals.begin(), diagonals.end(), comp);

		double ans = DBL_MAX;
		const int k = diagonals.size();
		int first = 0;
		for (int i = 0; i < k; ++i) {
			int next = i + 1;
			if (i == k - 1 || diagonals[i].center != diagonals[next].center || diagonals[i].len != diagonals[next].len)
				next = first, first = i + 1;
			if (next != i)
				ans = min(ans, areaRectDiagonal(diagonals[i], diagonals[next]));
		}
		return (ans == DBL_MAX) ? 0 : ans;
	}
};
