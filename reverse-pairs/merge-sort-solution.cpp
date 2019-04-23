class Solution {
private:
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
	static int reversePairs(vector<int>& nums) {
		int ans = 0;
		auto beforeMerged = [&](auto first, auto mid, auto last) {
			auto L = first;
			for (auto R = mid; R != last; ++R) {
				while (L != mid && *L <= 2 * (long long)*R)
					++L;
				ans += distance(L, mid);
			}
		};
		mergeSort(nums.begin(), nums.end(), beforeMerged);
		return ans;
	}
};
