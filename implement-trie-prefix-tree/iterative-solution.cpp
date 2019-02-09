class Trie {
private:
	bool end = false;
	Trie* next[26] = { };
public:
	/* time: O(1), space: O(1) */
	Trie() { }

	/* time: O(total # of nodes in trie), space: O(maximum depth in trie) */
	~Trie() {
		for (int i = 0; i < 26; ++i)
			delete next[i];
	}

	/* time: O(len(word)), space: O(1) auxiliary (i.e. does not count trie capacity itself) */
	void insert(const string& word) {
		auto p = this;
		for (char c : word) {
			if (!p->next[c - 'a'])
				p->next[c - 'a'] = new Trie();
			p = p->next[c - 'a'];
		}
		p->end = true;
	}

	/* time: O(len(word)), space: O(1) */
	bool search(const string& word) const {
		const Trie *p = this;
		for (char c : word) {
			if (!p->next[c - 'a'])
				return false;
			p = p->next[c - 'a'];
		}
		return p->end;
	}

	/* time: O(len(prefix)), space: O(1) */
	bool startsWith(const string& prefix) const {
		const Trie *p = this;
		for (char c : prefix) {
			if (!p->next[c - 'a'])
				return false;
			p = p->next[c - 'a'];
		}
		return true;
	}
};
