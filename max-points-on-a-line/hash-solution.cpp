class Solution {
private:
	typedef pair<int, int> PII;
	/*
	 * time: O(log(min(a,b))), space: O(1)
	 * see CLRS textbook 31.2: Greatest common divisor
	 */
	template <class T>
	T gcd(T a, T b) {
		if (b)
			while ((a %= b) && (b %= a));
		return a + b;
	}
public:
	/* time: O(n^2), space: O(n) */
	int maxPoints(const vector<Point>& points) {
		auto myHash = [](const PII& x) {
			return hash<int>()(x.first) ^ hash<int>()(x.second);
		};

		int ans = 0;
		for (auto u = points.begin(); u != points.end(); ++u) {
			unordered_map<PII, int, decltype(myHash)> slope2count(10, myHash);

			int nSelf = 1;
			for (auto v = u + 1; v != points.end(); ++v)
				if (u->x == v->x && u->y == v->y)
					++nSelf;
				else {
					const int dx = v->x - u->x, dy = v->y - u->y, c = gcd(dx, dy);
					++slope2count[make_pair(dx / c, dy / c)];
				}

			ans = max(ans, nSelf);
			for (auto it : slope2count)
				ans = max(ans, nSelf + it.second);
		}
		return ans;
	}
};
