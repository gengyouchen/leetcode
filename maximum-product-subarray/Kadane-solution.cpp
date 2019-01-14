class Solution {
public:
	/* time: O(n), space: O(1) */
	int maxProduct(const vector<int>& nums) {
		int _maxProd[2], _minProd[2];
		auto maxProd = [&](int i) -> int& { return _maxProd[i % 2]; };
		auto minProd = [&](int i) -> int& { return _minProd[i % 2]; };

		int ans = INT_MIN;
		for (int i = 0; i < nums.size(); ++i) {
			if (i == 0) {
				maxProd(i) = nums[i];
				minProd(i) = nums[i];
			} else {
				maxProd(i) = max(max(maxProd(i - 1) * nums[i], minProd(i - 1) * nums[i]), nums[i]);
				minProd(i) = min(min(maxProd(i - 1) * nums[i], minProd(i - 1) * nums[i]), nums[i]);
			}
			ans = max(ans, maxProd(i));
		}
		return ans;
	}
};
