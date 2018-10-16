class Solution {
public:
	/* time: O(n), space: O(1) */
	int longestValidParentheses(const string& s) {
		int ans = 0;
		auto scan = [&](auto first, auto last, char open) {
			int nOpened = 0;
			auto start = first;
			for (auto it = first; it != last; ++it) {
				nOpened = (*it == open) ? (nOpened + 1) : (nOpened - 1);
				if (nOpened == 0)
					ans = max(ans, (int)distance(start, it + 1));
				else if (nOpened < 0)
					start = it + 1, nOpened = 0;
			}
		};
		scan(s.begin(), s.end(), '(');
		scan(s.rbegin(), s.rend(), ')');
		return ans;
	}
};
