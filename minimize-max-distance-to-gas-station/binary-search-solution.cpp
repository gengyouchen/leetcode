class Solution {
private:
	template <class F>
	static double lowestTrue(double low, double high, F cond) {
		while (high - low > 1e-6) {
			const double mid = (low + high) / 2;
			if (cond(mid))
				high = mid;
			else
				low = mid;
		}
		return low;
	}
public:
	/* time: O(n*log(W)), space: O(1), where W = max distance between adjacent initial stations */
	static double minmaxGasDist(const vector<int>& stations, int K) {
		const int n = stations.size();
		int maxGap = 0;
		for (int i = 1; i < n; ++i)
			maxGap = max(maxGap, stations[i] - stations[i - 1]);

		auto cond = [&](double D) {
			int nPut = 0;
			for (int i = 1; i < n; ++i) {
				const double gap = stations[i] - stations[i - 1];
				if (D < gap) {
					const int nSegment = ceil(gap / D);
					nPut += nSegment - 1;
					if (nPut > K)
						return false;
				}
			}
			return true;
		};
		return lowestTrue(0.0, (double)maxGap, cond);
	}
};
