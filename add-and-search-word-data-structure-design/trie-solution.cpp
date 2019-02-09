class WordDictionary {
private:
	bool end = false;
	WordDictionary* next[26] = { };
	typedef string::const_iterator I;
	bool search(I first, I last) const {
		const WordDictionary *p = this;
		for (auto it = first; it != last; ++it) {
			if (*it != '.') {
				if (!p->next[*it - 'a'])
					return false;
				p = p->next[*it - 'a'];
			} else {
				for (int i = 0; i < 26; ++i) {
					if (p->next[i] && p->next[i]->search(it + 1, last))
						return true;
				}
				return false;
			}
		}
		return p->end;
	}
public:
	/* time: O(1), space: O(1) */
	WordDictionary() { }

	/* time: O(total # of nodes in trie), space: O(maximum depth in trie) */
	~WordDictionary() {
		for (int i = 0; i < 26; ++i)
			delete next[i];
	}

	/* time: O(len(word)), space: O(1) auxiliary (i.e. does not count trie capacity itself) */
	void addWord(const string& word) {
		auto p = this;
		for (char c : word) {
			if (!p->next[c - 'a'])
				p->next[c - 'a'] = new WordDictionary();
			p = p->next[c - 'a'];
		}
		p->end = true;
	}

	/* time: O(total # of nodes in trie), space: O(maximum depth in trie) */
	bool search(const string& word) const {
		return search(word.begin(), word.end());
	}
};
