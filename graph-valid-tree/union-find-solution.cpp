class DisjointSet {
private:
	vector<int> p, rank;
	int nSet;
public:
	DisjointSet(int n) : p(n), rank(n, 0), nSet(n) {
		iota(p.begin(), p.end(), 0);
	}
	int FindSet(int x) {
		if (p[x] != x)
			p[x] = FindSet(p[x]);
		return p[x];
	}
	void Union(int x, int y) {
		x = FindSet(x), y = FindSet(y);
		if (x != y) {
			--nSet;
			if (rank[x] > rank[y]) {
				p[y] = x;
			} else {
				p[x] = y;
				if (rank[x] == rank[y])
					++rank[y];
			}
		}
	}
	int CountSet() const {
		return nSet;
	};
};

class Solution {
public:
	/*
	 * time: O(k * alpha(k)) ~= O(k), space: O(n),
	 * where alpha(x) is the inverse Ackermann function, and k = |edges|
	 *
	 * Because alpha(x) < 5 for any value x that can be written in this physical universe,
	 * all the disjoint-set operations take place in essentially constant time.
	 */
	bool validTree(int n, const vector<pair<int, int>>& edges) {
		DisjointSet s(n);
		for (const auto& edge : edges) {
			const int u = edge.first, v = edge.second;
			if (s.FindSet(u) == s.FindSet(v))
				return false;
			s.Union(u, v);
		}
		return (s.CountSet() == 1);
	}
};
