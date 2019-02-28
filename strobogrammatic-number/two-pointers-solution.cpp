class Solution {
public:
	/* time: O(n), space: O(1), where n = length of number string */
	bool isStrobogrammatic(const string& num) {
		char h[256] = {};
		h['0'] = '0', h['1'] = '1', h['6'] = '9', h['8'] = '8', h['9'] = '6';

		const int n = num.size();
		int i = 0, j = n - 1;
		while (i <= j) {
			if (h[num[i]] != num[j])
				return false;
			++i, --j;
		}
		return true;
	}
};
