class Solution {
public:
	/* time: O(n), space: O(1) auxiliary (i.e. does not count input & output itself) */
	vector<int> plusOne(vector<int>& digits) {
		bool carry = true;
		for (auto it = digits.rbegin(); it != digits.rend(); ++it) {
			if (carry)
				++*it;
			carry = (*it == 10);
			if (carry)
				*it = 0;
		}
		if (carry)
			digits.insert(digits.begin(), 1);
		return digits;
	}
};
