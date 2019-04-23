class Solution {
private:
	typedef long long K;
	typedef vector<K>::iterator I;
	typedef function<void(I, I)> F;
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

		vector<K> buf(n + 1);
		F mergeSort = [&](auto first, auto last) {
			if (distance(first, last) > 1) {
				const auto mid = first + distance(first, last) / 2;
				mergeSort(first, mid), mergeSort(mid, last);

				beforeMerged(first, mid, last);

				const auto end = merge(first, mid, mid, last, buf.begin());
				copy(buf.begin(), end, first);
			}
		};
		mergeSort(S.begin(), S.end());
		return ans;
	}
};
