class Solution {
private:
	typedef function<void(int, int)> F;
public:
	/* time: O(2^n), space: O(n) auxiliary (i.e. does not count output itself) */
	vector<vector<string>> partition(const string& s) {
		const int n = s.size();
		/*
		 * Because printing all possible palindrome partitioning will take O(2^n) time,
		 * using Manacher's algorithm (time: O(n)) won't improve any time complexity.
		 *
		 * Therefore, we just use a simple expand-around-center method (time: O(n^2)).
		 * See LeetCode 5 - Longest Palindromic Substring
		 */
		const int len = n * 2 + 1;
		vector<int> r(len, 1);
		for (int i = 0; i < len; ++i) {
			while (i - r[i] >= 0 && i + r[i] < len) {
				if ((i - r[i]) % 2) {
					const int L = (i - r[i]) / 2, R = (i + r[i]) / 2;
					if (s[L] != s[R])
						break;
				}
				++r[i];
			}
		}
		auto isPalindrome = [&](int first, int last) {
			const int L = first * 2, R = last * 2, c = (L + R) / 2;
			return (r[c] * 2 - 1) >= (R - L + 1);
		};

		vector<vector<string>> ans;
		vector<int> pos;
		pos.push_back(0);
		F backtrack = [&](int first, int last) {
			if (first == last) {
				ans.emplace_back();
				for (int i = 0; i < pos.size() - 1; ++i)
					ans.back().push_back(s.substr(pos[i], pos[i + 1] - pos[i]));
			}
			for (int mid = first + 1; mid <= last; ++mid) {
				if (isPalindrome(first, mid)) {
					pos.push_back(mid);
					backtrack(mid, last);
					pos.pop_back();
				}
			}
		};
		backtrack(0, n);
		return ans;
	}
};
