class Solution {
public:
	/*
	 * time: O(c), space: O(1) auxiliary (i.e. does not count output itself),
	 * where c = total # of characters in A
	 */
	static vector<string> commonChars(const vector<string>& A) {
		if (A.empty())
			return {};

		array<int, 26> minCount;
		fill(minCount.begin(), minCount.end(), INT_MAX);

		for (const auto& s : A) {
			array<int, 26> count = {};
			for (char c : s)
				++count[c - 'a'];
			for (int i = 0; i < 26; ++i)
				minCount[i] = min(minCount[i], count[i]);
		}

		vector<string> ans;
		for (int i = 0; i < 26; ++i) {
			for (int j = 0; j < minCount[i]; ++j)
				ans.emplace_back(1, 'a' + i);
		}
		return ans;
	}
};
