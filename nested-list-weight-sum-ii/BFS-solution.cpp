class Solution {
public:
	/* time: O(n), space: O(n), where n = # of NestedInteger */
	static int depthSumInverse(const vector<NestedInteger>& nestedList) {
		int ans = 0, unweighted = 0;
		using I = vector<NestedInteger>::const_iterator;
		queue<I> Q;
		for (auto it = nestedList.begin(); it != nestedList.end(); ++it)
			Q.push(it);
		while (!Q.empty()) {
			for (int i = Q.size(); i > 0; --i) {
				const auto u = Q.front();
				Q.pop();
				if (u->isInteger()) {
					unweighted += u->getInteger();
				} else {
					for (auto v = u->getList().begin(); v != u->getList().end(); ++v)
						Q.push(v);
				}
			}
			ans += unweighted;
		}
		return ans;
	}
};
