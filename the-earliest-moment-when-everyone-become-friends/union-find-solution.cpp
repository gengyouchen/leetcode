class DisjointSet {
private:
	vector<int> p, rank;
	int nSet;
public:
	DisjointSet(int n) : p(n), rank(n), nSet(n) {
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
	int CountSet() const { return nSet; }
};

class Solution {
public:
	/*
	 * time: O(L*log(L) + N + L*alpha(N)) ~= O(L*log(L) + N), space: O(N) auxiliary (i.e. does not count input itself),
	 * where L = # of logs, and alpha(x) is the inverse Ackermann function.
	 *
	 * Because alpha(x) < 5 for any value x that can be written in this physical universe,
	 * all the disjoint-set operations take place in essentially constant time.
	 */
	static int earliestAcq(vector<vector<int>>& logs, int N) {
		make_heap(logs.begin(), logs.end());
		sort_heap(logs.begin(), logs.end());

		DisjointSet ds(N);
		for (const auto& it : logs) {
			ds.Union(it[1], it[2]);
			if (ds.CountSet() == 1)
				return it[0];
		}
		return -1;
	}
};
