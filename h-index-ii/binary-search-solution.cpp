class Solution {
private:
	template <class T, class F>
	static T lowestTrue(T min, T max, F cond) {
		while (min < max) {
			auto it = min + (max - min) / 2;
			if (cond(it) == true)
				max = it;
			else
				min = it + 1;
		}
		return min;
	}
public:
	/* time: O(log(n)), space: O(1) */
	static int hIndex(const vector<int>& citations) {
		const int n = citations.size();
		const int i = lowestTrue(0, n, [&](int i) { return citations[i] >= n - i; });
		return n - i;
	}
};
