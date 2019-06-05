class Solution {
public:
	/* time: O(n^2), space: O(n^2) */
	static int fourSumCount(const vector<int>& A, const vector<int>& B, const vector<int>& C, const vector<int>& D) {
		unordered_map<int, int> nTwoSum;
		for (int a : A) {
			for (int b : B)
				++nTwoSum[a + b];
		}

		int ans = 0;
		for (int c : C) {
			for (int d : D) {
				const auto it = nTwoSum.find(-(c + d));
				if (it != nTwoSum.end())
					ans += it->second;
			}
		}
		return ans;
	}
};
