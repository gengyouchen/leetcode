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
	int CountSet() const { return nSet; };
};

class Solution {
public:
	/*
	 * time: O(W + P + (n + k)* alpha(k)) ~= O(W + P + n + k) = O(W + P), space: O(P + k) = O(P),
	 * where W = total # of chars in words1 & words2, P = total # of chars in pairs,
	 * n = # words in words1 & words2, k = # of pair in pairs, and alpha(x) is the inverse Ackermann function
	 *
	 * Because alpha(x) < 5 for any value x that can be written in this physical universe,
	 * all the disjoint-set operations take place in essentially constant time.
	 */
	static bool areSentencesSimilarTwo(const vector<string>& words1, const vector<string>& words2, const vector<vector<string>>& pairs) {
		const int n = words1.size(), m = words2.size(), k = pairs.size();
		if (n != m)
			return false;

		DisjointSet s(k * 2);
		unordered_map<string, int> str2dictID;
		int dictID = 0;
		for (const auto& it : pairs) {
			int u, v;
			const auto x = str2dictID.find(it[0]), y = str2dictID.find(it[1]);
			if (x == str2dictID.end())
				u = str2dictID[it[0]] = dictID++;
			else
				u = x->second;
			if (y == str2dictID.end())
				v = str2dictID[it[1]] = dictID++;
			else
				v = y->second;
			s.Union(u, v);
		}

		for (int i = 0; i < n; ++i) {
			if (words1[i] != words2[i]) {
				const auto x = str2dictID.find(words1[i]), y = str2dictID.find(words2[i]);
				if (x == str2dictID.end() || y == str2dictID.end() || s.FindSet(x->second) != s.FindSet(y->second))
					return false;
			}
		}
		return true;
	}
};
