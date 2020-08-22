class Solution {
public:
	/* time: O(n), space: O(1) */
	static vector<int> twoSum(const vector<int>& numbers, int target) {
		const int n = numbers.size();
		vector<int> ans;
		int L = 0, R = n - 1;
		while (L < R) {
			const int sum = numbers[L] + numbers[R];
			if (sum < target)
				++L;
			else if (sum > target)
				--R;
			else
				return {L + 1, R + 1};
		}
		return {};
	}
};
