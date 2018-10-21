class Solution {
public:
	/* time: O(n), space: O(n), where n = total # of chars in all given strings */
	vector<vector<string>> groupStrings(const vector<string>& strings) {
		auto diff = [](char x, char y) { return (y - x + 26) % 26; };
		auto getGroupName = [&](const string& s) {
			string name;
			for (auto it = s.begin() + 1; it != s.end(); ++it)
				name.push_back('a' + diff(*(it - 1), *it));
			return name;
		};

		unordered_map<string, vector<string>> groups;
		for (const auto &s : strings)
			groups[getGroupName(s)].push_back(s);

		vector<vector<string>> ans;
		for (auto it = groups.begin(); it != groups.end(); ++it)
			ans.push_back(it->second);
		return ans;
	}
};
