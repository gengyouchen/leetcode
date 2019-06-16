class Solution {
private:
	typedef pair<int, int> PII;
public:
	/* time: O(n), space: O(W), where W = # of unique elements */
	static vector<int> topKFrequent(const vector<int>& nums, int k) {
		const int n = nums.size();
		unordered_map<int, int> num2freq;
		for (int num : nums)
			++num2freq[num];

		vector<PII> freqs;
		for (const auto& it : num2freq)
			freqs.emplace_back(it.second, it.first);
		nth_element(freqs.begin(), freqs.begin() + k, freqs.end(), greater<PII>());

		vector<int> ans(k);
		for (int i = 0; i < k; ++i)
			ans[i] = freqs[i].second;
		return ans;
	}
};
