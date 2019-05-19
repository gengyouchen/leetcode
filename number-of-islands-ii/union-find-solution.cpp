class DisjointSet {
private:
	vector<int> p, rank;
	int count = 0;
public:
	DisjointSet(int n) : p(n, -1), rank(n) {}
	int size() const { return count; };
	void make(int x) {
		if (p[x] == -1)
			p[x] = x, rank[x] = 0, ++count;
	}
	int find(int x) {
		if (p[x] != -1) {
			int root = x, next;
			while (p[root] != root)
				root = p[root];
			while (x != root)
				next = p[x], p[x] = root, x = next;
		}
		return p[x];
	}
	void setUnion(int x, int y) {
		x = find(x), y = find(y);
		if (x != -1 && y != -1 && x != y) {
			--count;
			if (rank[x] > rank[y])
				p[y] = x;
			else if (rank[x] < rank[y])
				p[x] = y;
			else
				p[x] = y, ++rank[y];
		}
	}
};

class Solution {
public:
	/*
	 * time: O(k * alpha(k)) ~= O(k), space: O(k),
	 * where alpha(x) is the inverse Ackermann function.
	 *
	 * Because alpha(x) < 5 for any value x that can be written in this physical universe,
	 * all the disjoint-set operations take place in essentially constant time.
	 */
	static vector<int> numIslands2(int m, int n, const vector<vector<int>>& positions) {
		const int k = positions.size();
		const vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

		vector<int> ans(k);
		DisjointSet s(k);
		unordered_map<int, int> location2set;
		for (int i = 0; i < k; ++i) {
			const int row = positions[i][0], col = positions[i][1];
			if (!location2set.count(row * n + col)) {
				location2set[row * n + col] = i, s.make(i);
				for (const auto& dir : dirs) {
					const int y = row + dir[0], x = col + dir[1];
					if (y >= 0 && y < m && x >= 0 && x < n) {
						const auto it = location2set.find(y * n + x);
						if (it != location2set.end())
							s.setUnion(i, it->second);
					}
				}
			}
			ans[i] = s.size();
		}
		return ans;
	}
};
