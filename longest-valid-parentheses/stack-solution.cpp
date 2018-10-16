class Solution {
public:
	/* time: O(n), space: O(n) */
	int longestValidParentheses(const string& s) {
		int ans = 0;
		stack<decltype(s.begin())> start;
		start.push(s.begin());
		for (auto it = s.begin(); it != s.end(); ++it)
			if (*it == '(')
				start.push(it + 1);
			else {
				start.pop();
				if (start.empty())
					start.push(it + 1);
				else
					ans = max(ans, (int)distance(start.top(), it + 1));
			}
		return ans;
	}
};
