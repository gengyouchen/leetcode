class Solution {
public:
	/* time: O(n), space: O(1) auxiliary (i.e. does not count input itself) */
	bool verifyPreorder(vector<int>& preorder) {
		/*
		 * Similar to the iterative DFS solution
		 * However, we use the input array's space
		 * to implement the stack of successor links
		 * in order to achieve O(1) auxiliary space
		 *
		 * Warning:
		 * this method will destroy the input array data
		 */
		int succ_size = 0;
		auto succ_empty = [&]() { return succ_size == 0; };
		auto succ_pop = [&]() { --succ_size; };
		auto succ_push = [&](int succ) { preorder[succ_size++] = succ; };
		auto succ_top = [&]() { return preorder[succ_size - 1]; };
		int pred = INT_MIN;

		for (int curr : preorder) {
			while (!succ_empty() && curr > succ_top()) {
				pred = succ_top();
				succ_pop();
			}

			/* verify the preorder sequence */
			if (!(curr > pred))
				return false;

			succ_push(curr);
		}
		return true;
	}
};
