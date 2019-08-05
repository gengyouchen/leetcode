class Solution {
public:
	/* time: O(n), space: O(n) */
	static vector<int> nextGreaterElements(const vector<int>& nums) {
		const int n = nums.size();
		vector<int> ans(n, -1);
		stack<int> mono;
		for (int i = 0; i < n * 2; ++i) {
			while (!mono.empty() && nums[mono.top()] < nums[i % n])
				ans[mono.top()] = nums[i % n], mono.pop();
			mono.push(i % n);
		}
		return ans;
	}
};
