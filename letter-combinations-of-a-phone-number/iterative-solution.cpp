class Solution {
public:
	/* time: O(# of total output chars), space: O(1) auxiliary (i.e. does not count output itself) */
	vector<string> letterCombinations(const string& digits) {
		vector<string> ans;

		unordered_map<char, string> digit2letters {
			{'2', "abc"}, {'3', "def"},
				{'4', "ghi"}, {'5', "jkl"}, {'6', "mno"},
				{'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"},
		};

		const int n = digits.size();
		vector<int> counter(n, 0);
		string buf(n, '?');
		while (n) {
			for (int i = 0; i < n; ++i)
				buf[i] = digit2letters[digits[i]][counter[i]];
			ans.push_back(buf);

			bool carry = true;
			for (int i = n - 1; i >= 0; --i) {
				if (carry)
					++counter[i];
				carry = (counter[i] == digit2letters[digits[i]].size());
				if (carry)
					counter[i] = 0;
			}
			if (carry)
				break;
		}
		return ans;
	}
};
