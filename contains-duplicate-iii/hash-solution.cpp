class Solution {
public:
	/* time: O(n), space: O(min(n,k)) */
	bool containsNearbyAlmostDuplicate(const vector<int>& nums, int k, int t) {
		if (t < 0)
			return false;
		const int n = nums.size();
		const long bucketSize = (long)t + 1; /* i.e. each bucket will only have one element */
		auto hash = [&](long num) -> long {
			if (num < 0)
				return (num + 1) / bucketSize - 1;
			return (num / bucketSize);
		};
		unordered_map<long, long> bucket;

		for (int i = 0; i < n; ++i) {
			const long bucketIndex = hash(nums[i]);

			if (bucket.count(bucketIndex))
				return true;
			if (bucket.count(bucketIndex - 1) && abs(nums[i] - bucket[bucketIndex - 1]) < bucketSize)
				return true;
			if (bucket.count(bucketIndex + 1) && abs(nums[i] - bucket[bucketIndex + 1]) < bucketSize)
				return true;

			bucket[bucketIndex] = nums[i];
			if (i >= k)
				bucket.erase(hash(nums[i - k]));
		}
		return false;
	}
};
