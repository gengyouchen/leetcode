class Solution {
private:
	typedef function<void(int, int)> F;
public:
	/* time: O(k * C(n, k)), space: O(k) auxiliary (i.e. does not count output itself) */
	vector<vector<int>> combine(int n, int k) {
		vector<vector<int>> ans;
		vector<int> buf;
		F backtrack = [&](int first, int last) {
			if (buf.size() == k)
				ans.push_back(buf);
			else
				for (int i = first; i != last; ++i) {
					buf.push_back(i);
					backtrack(i + 1, last);
					buf.pop_back();
				}
		};
		backtrack(1, n + 1);
		return ans;
	}
};
