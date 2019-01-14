class Solution {
private:
	typedef vector<int>::const_iterator I;
	typedef function<int(I, I)> F;
public:
	/* time: O(n*log(n)), space: O(log(n)) */
	int maxProduct(const vector<int>& nums) {
		auto prodAcross = [](auto first, auto mid, auto last) {
			int leftMax = INT_MIN, leftMin = INT_MAX, rightMax = INT_MIN, rightMin = INT_MAX, curr = 1;
			auto it = mid;
			do
				curr *= *--it, leftMax = max(leftMax, curr), leftMin = min(leftMin, curr);
			while (it != first);

			curr = 1, it = mid;
			do
				curr *= *it++, rightMax = max(rightMax, curr), rightMin = min(rightMin, curr);
			while (it != last);
			return max(leftMax * rightMax, leftMin * rightMin);
		};

		F prod = [&](auto first, auto last) {
			if (last - first == 1)
				return *first;
			const auto mid = first + (last - first) / 2;
			return max(max(prod(first, mid), prod(mid, last)), prodAcross(first, mid, last));
		};
		return prod(nums.begin(), nums.end());
	}
};
