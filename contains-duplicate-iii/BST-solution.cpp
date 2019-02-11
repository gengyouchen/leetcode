class Solution {
public:
	/* time: O(n*log(n,k)), space: O(min(n,k)), where n=len(nums) */
	bool containsNearbyAlmostDuplicate(const vector<int>& nums, int k, int t) {
		if (k <= 0 || t < 0)
			return false;
		set<long> appeared;
		for (auto it = nums.begin(); it != nums.end(); ++it) {
			auto prev = appeared.lower_bound((long)*it - (long)t);
			if (prev != appeared.end() && abs((long)*prev - (long)*it) <= t)
				return true;
			if (appeared.size() == k)
				appeared.erase(*(it - k));
			appeared.insert(*it);
		}
		return false;
	}
};
