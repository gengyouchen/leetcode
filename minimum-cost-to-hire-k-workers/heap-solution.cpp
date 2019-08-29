class Solution {
public:
	/* time: O(n*log(n)), space: O(n) */
	static double mincostToHireWorkers(const vector<int>& quality, const vector<int>& wage, int K) {
		const int n = quality.size();
		vector<pair<double, int>> workers(n);
		for (int i = 0; i < n; ++i)
			workers[i].first = (double)wage[i] / quality[i], workers[i].second = quality[i];
		sort(workers.begin(), workers.end());

		/*
		 * For each worker with a ratio R (wage / quality),
		 * find the min sum of K wages by selecting K workers which ratio <= R
		 */
		double ans = INT_MAX;
		int totalQuality = 0;
		priority_queue<int> pq;
		for (const auto& worker : workers) {
			totalQuality += worker.second, pq.push(worker.second);
			if (pq.size() > K)
				totalQuality -= pq.top(), pq.pop();

			if (pq.size() == K)
				ans = min(ans, worker.first * totalQuality);
		}
		return ans;
	}
};
