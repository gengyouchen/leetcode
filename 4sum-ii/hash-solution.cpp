class Solution {
public:
	/* time: O(n^2), space: O(n^2) */
	int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
		unordered_map<int, int> nTwoSum;
		for (int a : A)
			for (int b : B)
				++nTwoSum[a + b];

		int ans = 0;
		for (int c : C)
			for (int d : D) {
				auto complement = nTwoSum.find(-(c + d));
				if (complement != nTwoSum.end())
					ans += complement->second;
			}
		return ans;
	}
};
