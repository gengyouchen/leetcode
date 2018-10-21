class Solution {
public:
	/* time: O(n), space: O(n), where n = total # of characters in all given strings */
	vector<vector<string>> groupAnagrams(const vector<string>& strs) {
		auto getGroupName = [](const string& s) {
			int count[26] = {};
			for (char c : s)
				++count[c - 'a'];
			string name;
			for (int i = 0; i < 26; ++i)
				for (int j = 0; j < count[i]; ++j)
					name.push_back('a' + i);
			return name;
		};

		unordered_map<string, vector<string>> groups;
		for (const auto &s : strs)
			groups[getGroupName(s)].push_back(s);

		vector<vector<string>> ans;
		for (auto it = groups.begin(); it != groups.end(); ++it)
			ans.push_back(it->second);
		return ans;
	}
};
