class Solution {
public:
	/* time: O(log(n)), space: O(log(n)) */
	static int nextGreaterElement(int n) {
		auto digits = to_string(n);
		next_permutation(digits.begin(), digits.end());

		int ans = 0;
		try {
			ans = stoi(digits);
		} catch (const out_of_range& e) {
			ans = -1;
		}
		return (ans <= n) ? -1 : ans;
	}
};
