class Solution {
public:
	/* time: O(n), space: O(min(n,k)), where n=len(nums) */
	bool containsNearbyDuplicate(const vector<int>& nums, int k) {
		if (k <= 0)
			return false;
		unordered_set<int> appeared;
		for (auto it = nums.begin(); it != nums.end(); ++it) {
			if (appeared.count(*it))
				return true;
			if (appeared.size() == k)
				appeared.erase(*(it - k));
			appeared.insert(*it);
		}
		return false;
	}
};
