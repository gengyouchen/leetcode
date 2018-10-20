class Solution {
public:
	/* time: O(len(num1) * len(num2)), space: O(1) auxiliary (i.e. does not count output itself) */
	string multiply(const string& num1, const string& num2) {
		string ans(num1.size() + num2.size(), '0');
		for (auto it1 = num1.rbegin(); it1 != num1.rend(); ++it1)
			for (auto it2 = num2.rbegin(); it2 != num2.rend(); ++it2) {
				auto out = ans.begin() + distance(num1.rbegin(), it1) + distance(num2.rbegin(), it2);
				int product = (*out - '0') + (*it1 - '0') * (*it2 - '0');
				*out = ('0' + product % 10), *(out + 1) += product / 10;
			}

		while (ans.size() > 1 && ans.back() == '0')
			ans.pop_back();
		reverse(ans.begin(), ans.end());
		return ans;
	}
};
