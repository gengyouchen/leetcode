class Solution {
private:
	typedef function<void(int)> F;
public:
	/* time: O(k * C(n, k)), space: O(k) auxiliary (i.e. does not count output itself) */
	static vector<vector<int>> combine(int n, int k) {
		vector<vector<int>> ans;
		vector<int> buf;
		F backtrack = [&](int curr) {
			if (buf.size() == k) {
				ans.push_back(buf);
			} else {
				const int last = n - (k - buf.size() - 1); /* pruning */
				for (int i = curr; i <= last; ++i)
					buf.push_back(i), backtrack(i + 1), buf.pop_back();
			}
		};
		backtrack(1);
		return ans;
	}
};
