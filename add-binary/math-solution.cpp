class Solution {
public:
	/* time: O(max(len(a), len(b))), space: O(1) auxiliary (i.e. does not count output itself) */
	string addBinary(const string& a, const string& b) {
		string ans;
		bool carry = false;
		auto it1 = a.rbegin(), it2 = b.rbegin();
		while (it1 != a.rend() || it2 != b.rend() || carry) {
			int val = (carry ? 1 : 0);
			if (it1 != a.rend())
				val += (*it1 - '0'), ++it1;
			if (it2 != b.rend())
				val += (*it2 - '0'), ++it2;

			carry = (val >= 2);
			if (carry)
				val -= 2;

			ans.push_back('0' + val);
		}
		reverse(ans.begin(), ans.end());
		return ans;
	}
};
