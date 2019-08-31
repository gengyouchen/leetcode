class Trie {
private:
	Trie *child[26] = {};
	bool end = false;
public:
	template <class I>
	void insert(I first, I last) {
		Trie *p = this;
		for (auto it = first; it != last; ++it) {
			const int i = *it - 'a';
			if (!p->child[i])
				p->child[i] = new Trie();
			p = p->child[i];
		}
		p->end = true;
	}
	Trie* match(char c) const { return child[c - 'a']; }
	bool isEnd() const { return end; }
};

class StreamChecker {
private:
	int depth;
	Trie *root;
	deque<char> stream;
public:
	/* time: O(L), space: O(1) auxiliary (i.e. does not count trie itself), where L = total # of chars in all words */
	StreamChecker(const vector<string>& words) {
		depth = 0, root = new Trie();
		for (const auto& word : words)
			depth = max(depth, (int)word.size()), root->insert(word.rbegin(), word.rend());
	}

	/* time: O(depth), space: O(1) auxiliary (i.e. does not count trie itself), where depth = length of the longest word */
	bool query(char letter) {
		stream.push_front(letter);
		if (stream.size() > depth)
			stream.pop_back();

		Trie *p = root;
		for (char c : stream) {
			p = p->match(c);
			if (!p)
				return false;
			if (p->isEnd())
				return true;
		}
		return false;
	}
};
