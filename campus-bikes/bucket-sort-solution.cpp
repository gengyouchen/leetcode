class Solution {
private:
	static int Manhattan(const vector<int>& worker, const vector<int>& bike) {
		return abs(worker[0] - bike[0]) + abs(worker[1] - bike[1]);
	}
public:
	/* time: O(m*n), space: O(m*n), where n = # of workers, m = # of bikes */
	static vector<int> assignBikes(const vector<vector<int>>& workers, const vector<vector<int>>& bikes) {
		vector<vector<pair<int, int>>> buckets(2000);
		const int n = workers.size(), m = bikes.size();
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j)
				buckets[Manhattan(workers[i], bikes[j])].emplace_back(i, j);
		}

		vector<int> ans(n, -1);
		vector<bool> bikeUsed(m);
		for (const auto& bucket : buckets) {
			for (const auto& it : bucket) {
				if (ans[it.first] == -1 && !bikeUsed[it.second])
					ans[it.first] = it.second, bikeUsed[it.second] = true;
			}
		}
		return ans;
	}
};
