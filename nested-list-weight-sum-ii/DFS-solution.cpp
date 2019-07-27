class Solution {
public:
	/* time: O(n), space: O(n), where n = # of NestedInteger */
	static int depthSumInverse(const vector<NestedInteger>& nestedList) {
		int ans = 0, unweighted = 0, maxDepth = 0;
		using I = vector<NestedInteger>::const_iterator;
		stack<pair<I, int>> S;
		for (auto it = nestedList.begin(); it != nestedList.end(); ++it)
			S.emplace(it, 1);
		while (!S.empty()) {
			const auto u = S.top().first;
			const int depth = S.top().second;
			maxDepth = max(maxDepth, depth), S.pop();
			if (u->isInteger()) {
				ans += u->getInteger() * depth, unweighted += u->getInteger();
			} else {
				for (auto v = u->getList().begin(); v != u->getList().end(); ++v)
					S.emplace(v, depth + 1);
			}
		}
		return unweighted * (maxDepth + 1) - ans;
	}
};
