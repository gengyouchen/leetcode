class Solution {
private:
	typedef pair<int, int> PII;
	typedef vector<PII>::iterator I;
	typedef function<void(I, I)> F;
public:
	/* time: O(n*log(n)), space: O(n) */
	static vector<int> countSmaller(const vector<int>& nums) {
		const int n = nums.size();
		vector<PII> A(n);
		for (int i = 0; i < n; ++i)
			A[i].first = nums[i], A[i].second = i;

		vector<int> ans(n, 0);
		auto beforeMerged = [&](auto first, auto mid, auto last) {
			auto R = mid;
			for (auto L = first; L != mid; ++L) {
				while (R != last && R->first < L->first)
					++R;
				ans[L->second] += distance(mid, R);
			}
		};

		vector<PII> buf(n);
		F mergeSort = [&](auto first, auto last) {
			if (distance(first, last) > 1) {
				const auto mid = first + distance(first, last) / 2;
				mergeSort(first, mid), mergeSort(mid, last);

				beforeMerged(first, mid, last);

				const auto end = merge(first, mid, mid, last, buf.begin());
				copy(buf.begin(), end, first);
			}
		};
		mergeSort(A.begin(), A.end());
		return ans;
	}
};
