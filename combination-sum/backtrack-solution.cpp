class Solution {
private:
	typedef vector<int>::const_iterator I;
	typedef function<void(I, I, int)> F;
public:
	/*
	 * time: O(k * C(k + s, k)), space: O(k) auxiliary (i.e. does not count output itself)
	 * where k = target / min(candidates), s = len(candidates)
	 */
	vector<vector<int>> combinationSum(const vector<int>& candidates, int target) {
		vector<vector<int>> ans;
		vector<int> buf;
		F backtrack = [&](auto first, auto last, int target) {
			if (target == 0)
				ans.push_back(buf);
			else if (target > 0)
				for (auto it = first; it != last; ++it) {
					buf.push_back(*it);
					backtrack(it, last, target - *it);
					buf.pop_back();
				}
		};
		backtrack(candidates.begin(), candidates.end(), target);
		return ans;
	}
};
