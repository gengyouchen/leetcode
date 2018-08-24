class Solution {
private:
	template <class I, class F>
	TreeNode* construct(I firstPre, I lastPre, I firstPost, I lastPost, F findPost) {
		if (lastPre == firstPre)
			return NULL;
		TreeNode *root = new TreeNode(*firstPre);
		if (lastPre - firstPre > 1) {
			++firstPre, --lastPost;
			int lenLeft = findPost(*firstPre) - firstPost + 1;
			I midPre = firstPre + lenLeft, midPost = firstPost + lenLeft;
			root->left = construct(firstPre, midPre, firstPost, midPost, findPost);
			root->right = construct(midPre, lastPre, midPost, lastPost, findPost);
		}
		return root;
	}
public:
	/* time: O(n), space: O(n) */
	TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
		unordered_map<int, vector<int>::iterator> iterPost;
		for (auto it = post.begin(); it != post.end(); ++it)
			iterPost[*it] = it;
		return construct(pre.begin(), pre.end(), post.begin(), post.end(), [&](int val) {
			return iterPost[val];
		});
	}
};
