class ValidWordAbbr {
private:
	unordered_map<string, string> abbr2str;
	static string str2abbr(const string& s) {
		if (s.size() < 2)
			return s;
		return s.front() + to_string(s.size() - 2) + s.back();
	}
public:
	/*
	 * time: O(n), space: O(1) auxiliary (i.e. does not count hash table itself),
	 * where n = total # of chars in the input dictionary
	 */
	ValidWordAbbr(const vector<string>& dictionary) {
		for (const string& word : dictionary) {
			const string abbr = str2abbr(word);
			const auto it = abbr2str.find(abbr);
			if (it == abbr2str.end())
				abbr2str.emplace(abbr, word);
			else if (it->second != word)
				it->second = "";
		}
	}

	/* time: O(L), space: O(1), where L = word.size() */
	bool isUnique(const string& word) const {
		const auto it = abbr2str.find(str2abbr(word));
		if (it == abbr2str.end())
			return true;
		return (it->second == word);
	}
};
