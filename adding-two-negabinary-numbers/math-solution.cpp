class Solution {
public:
	/* time: O(max(m, n)), space: O(1) auxiliary (i.e. does not count output itself) */
	static vector<int> addNegabinary(const vector<int>& arr1, const vector<int>& arr2) {
		vector<int> ans;
		int carry = 0;
		auto it1 = arr1.rbegin(), it2 = arr2.rbegin();
		while (it1 != arr1.rend() || it2 != arr2.rend() || carry) {
			int val = carry;
			if (it1 != arr1.rend())
				val += *it1, ++it1;
			if (it2 != arr2.rend())
				val += *it2, ++it2;

			switch (val) {
				case -1:
					carry = 1, val = 1;
					break;
				case 0:
					carry = 0, val = 0;
					break;
				case 1:
					carry = 0, val = 1;
					break;
				case 2:
					carry = -1, val = 0;
					break;
				case 3:
					carry = -1, val = 1;
					break;
			}
			ans.push_back(val);
		}
		while (ans.size() > 1 && ans.back() == 0)
			ans.pop_back();
		reverse(ans.begin(), ans.end());
		return ans;
	}
};
