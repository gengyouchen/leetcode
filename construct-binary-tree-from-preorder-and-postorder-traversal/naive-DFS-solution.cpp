class Solution {
private:
	typedef vector<int>::const_iterator I;
	typedef unordered_map<int, I> H;
	typedef function<TreeNode*(I, I, I, I)> F;
public:
	/* time: O(n), space: O(n) */
	TreeNode* constructFromPrePost(const vector<int>& pre, const vector<int>& post) {
		if (pre.empty())
			return NULL;

		H val2postIter;
		for (auto it = post.begin(); it != post.end(); ++it)
			val2postIter[*it] = it;

		F dfs = [&](auto firstPre, auto lastPre, auto firstPost, auto lastPost) {
			auto curr = new TreeNode(*firstPre);
			if (distance(firstPre, lastPre) > 1) {
				++firstPre, --lastPost;
				const int L = distance(firstPost, val2postIter[*firstPre] + 1);
				const int R = distance(firstPost, lastPost) - L;

				if (L > 0)
					curr->left = dfs(firstPre, firstPre + L, firstPost, firstPost + L);
				if (R > 0)
					curr->right = dfs(lastPre - R, lastPre, lastPost - R, lastPost);
			}
			return curr;
		};
		return dfs(pre.begin(), pre.end(), post.begin(), post.end());
	}
};
