class Solution {
private:
	typedef function<void(int, int, int)> F;
public:
	/* time: O(k * C(9, k)), space: O(k) auxiliary (i.e. does not count output itself) */
	vector<vector<int>> combinationSum3(int k, int n) {
		vector<vector<int>> ans;
		vector<int> buf;
		F backtrack = [&](int first, int last, int n) {
			if (n == 0 && buf.size() == k)
				ans.push_back(buf);
			else if (n > 0 && buf.size() < k)
				for (int i = first; i != last; ++i) {
					buf.push_back(i);
					backtrack(i + 1, last, n - i);
					buf.pop_back();
				}
		};
		backtrack(1, 10, n);
		return ans;
	}
};
