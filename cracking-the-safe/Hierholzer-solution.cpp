class Solution {
public:
	/* time: O(k^n), space: O(k^n) */
	static string crackSafe(int n, int k) {
		if (n == 1) {
			string ans(k, '0');
			iota(ans.begin(), ans.end(), '0');
			return ans;
		}

		/*
		 * Create the de Bruijn graph
		 * See https://en.wikipedia.org/wiki/De_Bruijn_graph
		 */
		int nVertices = 1;
		for (int i = 0; i < n - 1; ++i)
			nVertices *= k;
		vector<int> nEdges(nVertices, k);

		/*
		 * Find an Euler Circuit using Hierholzer algorithm in O(E)
		 * See also: LeetCode 332 - Reconstruct Itinerary
		 */
		vector<int> seq;
		using F = function<void(int)>;
		F dfs = [&](int v) {
			while (nEdges[v])
				dfs((--nEdges[v] + v * k) % nVertices);
			seq.push_back(v);
		};
		dfs(0);
		reverse(seq.begin(), seq.end());

		/*
		 * Print the de Bruijn sequence
		 * See https://en.wikipedia.org/wiki/De_Bruijn_sequence
		 */
		string ans(n - 2 + seq.size(), '0');
		int out = n - 2;
		for (int v : seq)
			ans[out++] += v % k;
		return ans;
	}
};
