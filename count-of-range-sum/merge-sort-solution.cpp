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
	static int countRangeSum(const vector<int>& nums, int lower, int upper) {
		const int n = nums.size();
		vector<long long> prefix(n + 1);
		copy(nums.begin(), nums.end(), prefix.begin() + 1);
		partial_sum(prefix.begin(), prefix.end(), prefix.begin());

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
		mergeSort(prefix.begin(), prefix.end(), beforeMerged);
		return ans;
	}
};
