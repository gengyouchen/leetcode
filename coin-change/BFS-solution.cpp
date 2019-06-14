class Solution {
public:
	/* time: O(amount * len(coins)), space: O(amount) */
	static int coinChange(const vector<int>& coins, int amount) {
		vector<bool> visited(amount + 1);
		queue<int> Q;
		Q.push(0), visited[0] = true;
		for (int depth = 0; !Q.empty(); ++depth) {
			for (int i = Q.size() - 1; i >= 0; --i) {
				const int u = Q.front();
				Q.pop();
				if (u == amount)
					return depth;
				for (long coin : coins) {
					const long v = u + coin;
					if (v <= amount && !visited[v])
						Q.push(v), visited[v] = true;
				}
			}
		}
		return -1;
	}
};
