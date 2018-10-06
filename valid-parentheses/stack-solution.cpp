class Solution {
public:
	/* time: O(n), space: O(n) */
	bool isValid(const string& s) {
		unordered_map<char, char> closed2opened {
			{'(', '?'}, {')', '('},
			{'[', '?'}, {']', '['},
			{'{', '?'}, {'}', '{'}
		};
		stack<char> opened;
		for (char c : s)
			if (!opened.empty() && opened.top() == closed2opened[c])
				opened.pop();
			else
				opened.push(c);
		return opened.empty();
	}
};
