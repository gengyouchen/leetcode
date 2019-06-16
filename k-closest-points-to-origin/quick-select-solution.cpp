class Solution {
public:
	/* time: O(n), space: O(1) auxiliary (i.e. does not count input & output itself) */
	static vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
		auto comp = [&](const auto& a, const auto& b) {
			return (a[0] * a[0] + a[1] * a[1]) < (b[0] * b[0] + b[1] * b[1]);
		};
		nth_element(points.begin(), points.begin() + (K - 1), points.end(), comp);

		vector<vector<int>> ans(K);
		copy_n(points.begin(), K, ans.begin());
		return ans;
	}
};
