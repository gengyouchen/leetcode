class Solution {
public:
	/* time: O(n^2), space: O(n) */
	string getPermutation(int n, int k) {
		--k; /* convert to zero-based numbering */

		vector<int> choices(n);
		iota(choices.begin(), choices.end(), 1);

		int nPermutation = 1;
		for (int i = 2; i <= choices.size(); ++i)
			nPermutation *= i;

		string ans;
		while (!choices.empty()) {
			nPermutation /= choices.size();

			const auto it = choices.begin() + k / nPermutation;
			ans.push_back('0' + *it);
			choices.erase(it);

			k %= nPermutation;
		}
		return ans;
	}
};
