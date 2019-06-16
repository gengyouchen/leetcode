class Solution {
public:
	/* time: O(n), space: O(W), where W = # of unique elements */
	static vector<int> topKFrequent(const vector<int>& nums, int k) {
		const int n = nums.size();
		unordered_map<int, int> num2freq;
		for (int num : nums)
			++num2freq[num];

		unordered_map<int, vector<int>> freq2nums(n + 1);
		for (const auto& it : num2freq)
			freq2nums[it.second].push_back(it.first);

		vector<int> ans;
		for (int freq = n; freq > 0; --freq) {
			const auto it = freq2nums.find(freq);
			if (it != freq2nums.end()) {
				for (int num : it->second) {
					if (ans.size() >= k)
						return ans;
					ans.push_back(num);
				}
			}
		}
		return ans;
	}
};
