class Solution {
public:
	/* time: O(n), space: O(n) */
	bool verifyPreorder(vector<int>& preorder) {
		/*  
		 * Track the successor link to mimic the threaded binary tree
		 * in order to know when should we stop traversing the sub-tree
		 *
		 * The predecessor link is no need for traversing the sub-tree
		 * We only use it to verify the preorder sequence is valid or not
		 */
		stack<int> succ;
		int pred = INT_MIN;

		for (int curr : preorder) {
			while (!succ.empty() && curr > succ.top()) {
				pred = succ.top();
				succ.pop();
			}

			/* verify the preorder sequence */
			if (!(curr > pred))
				return false;

			succ.push(curr);
		}
		return true;
	}
};
