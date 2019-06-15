class Solution {
public:
	/* time: O(n), space: O(n) */
	static vector<int> topKFrequent(const vector<int>& nums, int k) {
		const int n = nums.size();
		unordered_map<int, int> num2freq;
		for (int num : nums)
			++num2freq[num];

		vector<vector<int>> freq2nums(n + 1);
		for (const auto& it : num2freq)
			freq2nums[it.second].push_back(it.first);

		vector<int> ans;
		for (int freq = n; freq > 0; --freq) {
			for (int num : freq2nums[freq]) {
				if (ans.size() >= k)
					return ans;
				ans.push_back(num);
			}
		}
		return ans;
	}
};
