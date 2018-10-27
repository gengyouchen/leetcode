class Solution {
private:
	typedef vector<int>::const_iterator I;
	typedef function<int(I, I)> F;
public:
	/* time: O(n*log(n)), space: O(log(n)) */
	int maxSubArray(const vector<int>& nums) {
		auto sumAcross = [](auto first, auto mid, auto last) {
			int leftSum = INT_MIN, rightSum = INT_MIN, curr = 0;
			auto it = mid;
			do
				curr += *--it, leftSum = max(leftSum, curr);
			while (it != first);

			curr = 0, it = mid;
			do
				curr += *it++, rightSum = max(rightSum, curr);
			while (it != last);
			return leftSum + rightSum;
		};

		F sum = [&](auto first, auto last) {
			if (last - first == 1)
				return *first;
			const auto mid = first + (last - first) / 2;
			return max(max(sum(first, mid), sum(mid, last)), sumAcross(first, mid, last));
		};
		return sum(nums.begin(), nums.end());
	}
};
