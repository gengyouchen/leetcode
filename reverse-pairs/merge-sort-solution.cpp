class Solution {
private:
	typedef vector<int>::iterator I;
	typedef function<void(I, I)> F;
public:
	/* time: O(n*log(n)), space: O(n) */
	static int reversePairs(vector<int>& nums) {
		const int n = nums.size();
		int ans = 0;
		auto beforeMerged = [&](auto first, auto mid, auto last) {
			auto L = first;
			for (auto R = mid; R != last; ++R) {
				while (L != mid && *L <= 2 * (long long)*R)
					++L;
				ans += distance(L, mid);
			}
		};

		vector<int> buf(n);
		F mergeSort = [&](auto first, auto last) {
			if (distance(first, last) > 1) {
				const auto mid = first + distance(first, last) / 2;
				mergeSort(first, mid), mergeSort(mid, last);

				beforeMerged(first, mid, last);

				const auto end = merge(first, mid, mid, last, buf.begin());
				copy(buf.begin(), end, first);
			}
		};
		mergeSort(nums.begin(), nums.end());
		return ans;
	}
};
