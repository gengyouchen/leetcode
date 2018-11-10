class Trie {
private:
	bool end = false;
	Trie* next[26] = { };
	int size = 0;
public:
	~Trie() {
		for (int i = 0; i < 26; ++i)
			delete next[i];
	}
	bool exist(const string& s) const {
		auto p = this;
		for (char c : s) {
			if (!p->next[c - 'a'] || !p->next[c - 'a']->size)
				return false;
			p = p->next[c - 'a'];
		}
		return p->end;
	}
	void insert(const string& s) {
		if (!exist(s)) {
			auto p = this;
			for (char c : s) {
				if (!p->next[c - 'a'])
					p->next[c - 'a'] = new Trie();
				++p->size, p = p->next[c - 'a'];
			}
			++p->size, p->end = true;
		}
	}
	void erase(const string& s) {
		if (exist(s)) {
			auto p = this;
			for (char c : s)
				--p->size, p = p->next[c - 'a'];
			--p->size, p->end = false;
		}
	}
	auto match(char c) const {
		return (next[c - 'a'] && next[c - 'a']->size) ? next[c - 'a'] : NULL;
	}
	bool ended() const { return size && end; }
	bool count() const { return size; }
};

class Solution {
private:
	typedef function<bool(int, int, Trie*)> F;
public:
	/*
	 * time: O(m*n*(3^k) + L), space: O(k + L) auxiliary (i.e. does not count input itself),
	 * where m = # of rows, n = # of cols, k = len of the longest word, L = total len of all words
	 */
	vector<string> findWords(vector<vector<char>>& board, const vector<string>& words) {
		const int m = board.size(), n = board[0].size();
		Trie dict;
		for (const string& word : words)
			dict.insert(word);

		vector<string> ans;
		string buf;
		F backtrack = [&](int row, int col, Trie *p) {
			if ((row < 0) || (row >= m) || (col < 0) || (col >= n) || !p)
				return false;

			const char c = board[row][col];
			if (c == '*' || !p->match(c))
				return false;

			buf.push_back(c), board[row][col] = '*';
			if (p->match(c)->ended())
				ans.push_back(buf), dict.erase(buf);

			bool found = false;
			if (!found)
				found = backtrack(row + 1, col, p->match(c));
			if (!found)
				found = backtrack(row - 1, col, p->match(c));
			if (!found)
				found = backtrack(row, col + 1, p->match(c));
			if (!found)
				found = backtrack(row, col - 1, p->match(c));

			buf.pop_back(), board[row][col] = c;
			return found;
		};

		for (int row = 0; row < m; ++row)
			for (int col = 0; col < n; ++col)
				if (dict.count())
					backtrack(row, col, &dict);
		return ans;
	}
};
