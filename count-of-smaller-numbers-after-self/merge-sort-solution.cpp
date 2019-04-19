class Solution {
private:
	template <class I, class F>
	static void mergeSort(I first, I last, F beforeMerged) {
		if (distance(first, last) > 1) {
			const I mid = first + distance(first, last) / 2;
			mergeSort(first, mid, beforeMerged), mergeSort(mid, last, beforeMerged);
			beforeMerged(first, mid, last), inplace_merge(first, mid, last);
		}
	}
public:
	/* time: O(n*log(n)), space: O(n) */
	static vector<int> countSmaller(const vector<int>& nums) {
		const int n = nums.size();
		vector<pair<int, int>> A;
		for (int i = 0; i < n; ++i)
			A.emplace_back(nums[i], i);

		vector<int> ans(n, 0);
		auto beforeMerged = [&](auto first, auto mid, auto last) {
			auto R = mid;
			for (auto L = first; L != mid; ++L) {
				while (R != last && R->first < L->first)
					++R;
				ans[L->second] += distance(mid, R);
			}
		};
		mergeSort(A.begin(), A.end(), beforeMerged);
		return ans;
	}
};
