class Solution {
private:
	typedef vector<int>::iterator I;
	typedef function<void(I, I, int)> F;
public:
	/*
	 * time: O(k * (2 ^ k)), space: O(k) auxiliary (i.e. does not count input & output itself)
	 * where k = len(candidates)
	 */
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		make_heap(candidates.begin(), candidates.end());
		sort_heap(candidates.begin(), candidates.end());
		vector<vector<int>> ans;
		vector<int> buf;
		F backtrack = [&](auto first, auto last, int target) {
			if (target == 0)
				ans.push_back(buf);
			else if (target > 0)
				for (auto it = first; it != last; ++it) {
					if (it != first && *it == *(it - 1))
						continue; /* skip duplicates */
					buf.push_back(*it);
					backtrack(it + 1, last, target - *it);
					buf.pop_back();
				}
		};
		backtrack(candidates.begin(), candidates.end(), target);
		return ans;
	}
};
