class DisjointSet {
private:
	vector<int> p, rank;
	vector<double> ratio;
	int nSet;
public:
	DisjointSet(int n) : p(n), rank(n), ratio(n, 1.0), nSet(n) {
		iota(p.begin(), p.end(), 0);
	}
	pair<int, double> FindSet(int x) {
		double r;
		if (p[x] != x)
			tie(p[x], r) = FindSet(p[x]), ratio[x] *= r;
		return {p[x], ratio[x]};
	}
	void Union(int x, int y, double r) {
		double r1, r2;
		tie(x, r1) = FindSet(x), tie(y, r2) = FindSet(y), r *= r2 / r1;
		if (x != y) {
			--nSet;
			if (rank[x] > rank[y]) {
				p[y] = x, ratio[y] = 1 / r;
			} else {
				p[x] = y, ratio[x] = r;
				if (rank[x] == rank[y])
					++rank[y];
			}
		}
	}
	int CountSet() const { return nSet; }
};

class Solution {
public:
	/*
	 * time: O(E + Q + (n + m)* alpha(n)) ~= O(E + Q + n + m) = O(E + Q), space: O(E + n) = O(E) auxiliary (i.e. does not count output itself),
	 * where E = total # of chars in equations, Q = total # of chars in queries, n = # of equations, m = # of queries,
	 * and alpha(x) is the inverse Ackermann function.
	 *
	 * Because alpha(x) < 5 for any value x that can be written in this physical universe,
	 * all the disjoint-set operations take place in essentially constant time.
	 */
	static vector<double> calcEquation(const vector<vector<string>>& equations, const vector<double>& values, const vector<vector<string>>& queries) {
		const int n = equations.size(), m = queries.size();

		DisjointSet ds(n * 2);
		unordered_map<string, int> var2dictID;
		int dictID = 0;
		for (int i = 0; i < n; ++i) {
			const auto& equation = equations[i];
			const double ratio = values[i];
			int u, v;
			const auto x = var2dictID.find(equation[0]), y = var2dictID.find(equation[1]);
			if (x == var2dictID.end())
				u = var2dictID[equation[0]] = dictID++;
			else
				u = x->second;
			if (y == var2dictID.end())
				v = var2dictID[equation[1]] = dictID++;
			else
				v = y->second;
			ds.Union(u, v, ratio);
		}

		vector<double> ans(m, -1);
		for (int i = 0; i < m; ++i) {
			const auto& query = queries[i];
			const auto x = var2dictID.find(query[0]), y = var2dictID.find(query[1]);
			if (x == var2dictID.end() || y == var2dictID.end())
				continue;

			const auto p1 = ds.FindSet(x->second), p2 = ds.FindSet(y->second);
			if (p1.first != p2.first)
				continue;

			ans[i] = p1.second / p2.second;
		}
		return ans;
	}
};
