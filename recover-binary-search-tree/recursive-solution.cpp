class Solution {
private:
	typedef function<void(TreeNode*)> F;
public:
	/* time: O(n), space: O(n) */
	void recoverTree(TreeNode* root) {
		TreeNode *prev = NULL, *wrong1 = NULL, *wrong2 = NULL;
		F dfs = [&](auto p) {
			if (p) {
				dfs(p->left);
				if (prev && prev->val >= p->val) {
					if (!wrong1)
						wrong1 = prev;
					wrong2 = p;
				}
				prev = p;
				dfs(p->right);
			}
		};
		dfs(root);
		swap(wrong1->val, wrong2->val);
	}
};
