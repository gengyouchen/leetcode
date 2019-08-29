class Solution {
public:
	/*
	 * time: O(W + P), space: O(P),
	 * where W = total # of chars in words1 & words2, P = total # of chars in pairs,
	 */
	static bool areSentencesSimilar(const vector<string>& words1, const vector<string>& words2, const vector<vector<string>>& pairs) {
		const int n = words1.size(), m = words2.size();
		if (n != m)
			return false;

		unordered_map<string, unordered_set<string>> adjLists;
		for (const auto& it : pairs)
			adjLists[it[0]].insert(it[1]), adjLists[it[1]].insert(it[0]);

		for (int i = 0; i < n; ++i) {
			if (words1[i] != words2[i]) {
				auto it = adjLists.find(words1[i]);
				if (it == adjLists.end())
					return false;
				const auto& adjList = it->second;
				if (!adjList.count(words2[i]))
					return false;
			}
		}
		return true;
	}
};
