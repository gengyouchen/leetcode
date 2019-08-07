class Solution {
private:
	template <class T, class F>
	static T lowestTrue(T low, T high, F cond) {
		while (low < high) {
			const auto mid = low + (high - low) / 2;
			if (cond(mid))
				high = mid;
			else
				low = mid + 1;
		}
		return low;
	}
public:
	/* time: O(n*log(s)), space: O(1), where n = len(nums), s = sum(nums) */
	static int splitArray(const vector<int>& nums, int m) {
		using LL = long long;
		auto canSplit = [&](LL sum) {
			int k = 1;
			LL curr = 0;
			for (int num : nums) {
				if (num > sum)
					return false;
				curr += num;
				if (curr > sum)
					++k, curr = num;
				if (k > m)
					return false;
			}
			return true;
		};

		LL maxSum = 0;
		for (int num : nums)
			maxSum += num;
		return lowestTrue(0LL, maxSum, canSplit);
	}
};
