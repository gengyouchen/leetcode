class Solution {
private:
	/* See LeetCode 31 - Next Permutation */
	static void nextPermutation(string& str) {
		const auto it = is_sorted_until(str.rbegin(), str.rend());
		if (it != str.rend()) {
			auto cond = [&](char c) { return c > *it; };
			const auto next = find_if(str.rbegin(), str.rend(), cond);
			iter_swap(it, next);
		}
		reverse(str.rbegin(), it);
	}
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
