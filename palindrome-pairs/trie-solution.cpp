class Trie {
private:
	Trie* next[26] = {};
	bool end = false;
	int value;
public:
	template <class I>
	void insert(I first, I last, int value) {
		auto p = this;
		for (auto it = first; it != last; ++it) {
			if (!p->next[*it - 'a'])
				p->next[*it - 'a'] = new Trie();
			p = p->next[*it - 'a'];
		}
		p->value = value, p->end = true;
	}
	template <class I, class F>
	bool match(I first, I last, F found) const {
		auto p = this;
		if (p->end)
			found(p->value);
		for (auto it = first; it != last; ++it) {
			if (!p->next[*it - 'a'])
				return false;
			p = p->next[*it - 'a'];
			if (p->end)
				found(p->value);
		}
		return true;
	}
};

class Manacher {
private:
	vector<int> r;
public:
	Manacher(const string& s) {
		const int n = s.size() * 2 + 1;
		r.resize(n, 1);
		auto expand = [&](int i) {
			while (i - r[i] >= 0 && i + r[i] < n) {
				const int L = i - r[i], R = i + r[i];
				if (L % 2 && s[L / 2] != s[R / 2])
					break;
				++r[i];
			}
		};

		int c = 0;
		for (int i = 0; i < n; ++i) {
			if (i >= c + r[c]) {
				expand(i), c = i;
			} else {
				const int j = c - (i - c); /* mirrored i */
				if (i + r[j] < c + r[c])
					r[i] = r[j];
				else if (i + r[j] > c + r[c])
					r[i] = c + r[c] - i;
				else
					r[i] = r[j], expand(i), c = i;
			}
		}
	}
	bool isPalindrome(int i, int j) const {
		const int L = i * 2 + 1, R = j * 2 + 1, c = L + (R - L + 1) / 2;
		return R < c + r[c];
	}
};

class Solution {
public:
	/* time: O(c), space: O(c), where c = total # of chars in words */
	static vector<vector<int>> palindromePairs(const vector<string>& words) {
		const int n = words.size();

		vector<Manacher> LUT;
		for (const auto& word : words)
			LUT.emplace_back(word);

		Trie dict, revDict;
		for (int i = 0; i < n; ++i)
			revDict.insert(words[i].rbegin(), words[i].rend(), i);

		unordered_set<int> ans;
		for (int i = 0; i < n; ++i) {
			const auto& A = words[i];
			auto found = [&](int j) {
				const auto& B = words[j];
				if (i == j)
					return;
				if (A.size() == B.size() || LUT[i].isPalindrome(B.size(), A.size() - 1))
					ans.insert(i * n + j);
			};
			if (revDict.match(A.begin(), A.end(), found))
				dict.insert(A.begin(), A.end(), i); /* speed up: no need to insert every word into dict */
		}

		for (int j = 0; j < n; ++j) {
			const auto& B = words[j];
			auto found = [&](int i) {
				const auto& A = words[i];
				if (i == j)
					return;
				if (A.size() == B.size() || LUT[j].isPalindrome(0, B.size() - A.size() - 1))
					ans.insert(i * n + j);
			};
			dict.match(B.rbegin(), B.rend(), found);
		}

		vector<vector<int>> out;
		for (int i : ans)
			out.push_back({i / n, i % n});
		return out;
	}
};
