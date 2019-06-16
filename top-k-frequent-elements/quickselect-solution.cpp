class Solution {
private:
	/* See CLRS textbook 9.2: Selection in expected linear time */
	template <class I, class F>
	static void quickselect(I first, I nth, I last, F comp) {
		auto pred = [&](const auto& val) { return comp(val, *(last - 1)); };
		while (last - first > 1) {
			iter_swap(first + rand() % (last - first), last - 1);
			const auto pivot = partition(first, last - 1, pred);
			iter_swap(pivot, last - 1);
			if (nth < pivot)
				last = pivot;
			else if (nth > pivot)
				first = pivot + 1;
			else
				break;
		}
	}
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
		quickselect(freqs.begin(), freqs.begin() + (k - 1), freqs.end(), greater<PII>());

		vector<int> ans(k);
		for (int i = 0; i < k; ++i)
			ans[i] = freqs[i].second;
		return ans;
	}
};
