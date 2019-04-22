class Solution {
private:
	typedef long long K;
	template <class I, class F>
	static void mergeSort(I first, I last, F beforeMerged) {
		if (distance(first, last) > 1) {
			const auto mid = first + distance(first, last) / 2;
			mergeSort(first, mid, beforeMerged), mergeSort(mid, last, beforeMerged);
			beforeMerged(first, mid, last), inplace_merge(first, mid, last);
		}
	}
public:
	/* time: O(n*log(n)), space: O(n) */
	static int countRangeSum(const vector<int>& nums, int lower, int upper) {
		const int n = nums.size();
		vector<K> S(n + 1);
		for (int i = 1; i <= n; ++i)
			S[i] = S[i - 1] + nums[i - 1];

		int ans = 0;
		auto beforeMerged = [&](auto first, auto mid, auto last) {
			auto L0 = first, L1 = first;
			for (auto R = mid; R != last; ++R) {
				while (L0 != mid && *L0 < *R - upper)
					++L0;
				while (L1 != mid && *L1 <= *R - lower)
					++L1;
				ans += distance(L0, L1);
			}
		};
		mergeSort(S.begin(), S.end(), beforeMerged);
		return ans;
	}
};
