class Solution {
private:
	template <class T, class F>
	T lowestTrue(T min, T max, F cond) {
		while (min < max) {
			const auto it = min + (max - min) / 2;
			if (cond(it) == true)
				max = it;
			else
				min = it + 1;
		}
		return min;
	}
	int countCompleteTreeHeight(const TreeNode* root) {
		int count = 0;
		while (root)
			root = root->left, ++count;
		return count;
	}
public:
	/* time: O((log(n))^2), space: O(1) */
	int countNodes(const TreeNode* root) {
		if (!root)
			return 0;
		const int nStep = countCompleteTreeHeight(root) - 1;
		if (!nStep)
			return 1;

		auto traverse = [&](int path) {
			auto curr = root;
			for (int i = 0; i < nStep; ++i) {
				if (path & (1 << (nStep - i - 1)))
					curr = curr->right;
				else
					curr = curr->left;
			}
			return (curr == NULL);
		};
		const int nLastLevelNodes = lowestTrue(0, 1 << nStep, traverse);

		return ((1 << nStep) - 1) + nLastLevelNodes;
	}
};
