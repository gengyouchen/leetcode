class WordDistance {
private:
	unordered_map<string, vector<int>> word2idx;
public:
	/*
	 * time: O(c), space: O(1) auxiliary (i.e. does not count hash table itself),
	 * where c = total # of chars in words
	 */
	WordDistance(const vector<string>& words) {
		const int n = words.size();
		for (int i = 0; i < n; ++i)
			word2idx[words[i]].push_back(i);
	}
	/*
	 * time: O(max(m,n)), space: O(1) auxiliary (i.e. does not count hash table itself),
	 * where m = # of times word1 occured, n = # of times word2 occured
	 */
	int shortest(const string& word1, const string& word2) {
		const auto &idx1 = word2idx[word1], &idx2 = word2idx[word2];
		int ans = INT_MAX;
		auto it1 = idx1.begin(), it2 = idx2.begin();
		while (it1 != idx1.end() && it2 != idx2.end()) {
			ans = min(ans, abs(*it1 - *it2));
			if (*it1 < *it2)
				++it1;
			else
				++it2;
		}
		return ans;
	}
};
