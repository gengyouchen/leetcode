class Solution {
private:
	typedef function<bool(int, int)> F;
public:
	/* time: O(n), space: O(n) */
	bool verifyPreorder(vector<int>& preorder) {
		auto it = preorder.begin();

		/*
		 * Propagate the successor link to mimic the threaded binary tree
		 * in order to know when should we stop traversing the sub-tree
		 *
		 * The predecessor link is no need for traversing the sub-tree
		 * We only use it to verify the preorder sequence is valid or not
		 */
		F dfs = [&](int pred, int succ) {
			if (it != preorder.end() && *it < succ) {
				int curr = *it++;

				/* verify the preorder sequence */
				if (!(curr > pred))
					return false;

				if (!dfs(pred, curr))
					return false;
				if (!dfs(curr, succ))
					return false;
			}
			return true;
		};

		return dfs(INT_MIN, INT_MAX);
	}
};
