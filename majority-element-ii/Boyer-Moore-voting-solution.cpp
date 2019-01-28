class Solution {
public:
	/* time: O(n), space: O(1) */
	vector<int> majorityElement(const vector<int>& nums) {
		const int n = nums.size();
		int candidate[2], nVote[2] = {};
		for (auto it = nums.begin(); it != nums.end(); ++it) {
			if (nVote[0] && *it == candidate[0])
				++nVote[0];
			else if (nVote[1] && *it == candidate[1])
				++nVote[1];
			else if (!nVote[0])
				candidate[0] = *it, nVote[0] = 1;
			else if (!nVote[1])
				candidate[1] = *it, nVote[1] = 1;
			else
				--nVote[0], --nVote[1];
		}

		vector<int> ans;
		if (nVote[0] && count(nums.begin(), nums.end(), candidate[0]) > n / 3)
			ans.push_back(candidate[0]);
		if (nVote[1] && count(nums.begin(), nums.end(), candidate[1]) > n / 3)
			ans.push_back(candidate[1]);
		return ans;
	}
};
