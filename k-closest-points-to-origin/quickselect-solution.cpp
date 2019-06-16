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
public:
	/* time: O(n), space: O(1) auxiliary (i.e. does not count input & output itself) */
	static vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
		auto comp = [&](const auto& a, const auto& b) {
			return (a[0] * a[0] + a[1] * a[1]) < (b[0] * b[0] + b[1] * b[1]);
		};
		quickselect(points.begin(), points.begin() + (K - 1), points.end(), comp);

		vector<vector<int>> ans(K);
		copy_n(points.begin(), K, ans.begin());
		return ans;
	}
};
