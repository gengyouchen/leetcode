class Solution {
public:
	/* time: O(n), space: O(1) */
	int majorityElement(const vector<int>& nums) {
		int candidate, nVote = 0;
		for (auto it = nums.begin(); it != nums.end(); ++it) {
			if (!nVote)
				candidate = *it, nVote = 1;
			else if (*it == candidate)
				++nVote;
			else
				--nVote;
		}
		return candidate;
	}
};
