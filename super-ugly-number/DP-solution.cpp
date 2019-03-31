class Solution {
private:
	typedef pair<int, int> PII;
	typedef priority_queue<PII, vector<PII>, greater<PII>> MinHeap;
public:
	/* time: O(n*log(k) + k), space: O(n + k), where k = |primes| */
	int nthSuperUglyNumber(int n, const vector<int>& primes) {
		const int k = primes.size();
		/*
		 * If k = 3,
		 * this is exactly the same problem as LeetCode 264 - Ugly Number II.
		 *
		 * We just use MinHeap to reduce time from O(n*k) to O(n*log(k) + k).
		 */
		vector<int> ugly;
		ugly.push_back(1);

		auto L = [&](int name, int i) -> int { return ugly[i] * primes[name]; };

		vector<int> index(k, 0);
		MinHeap q;
		for (int name = 0; name < k; ++name)
			q.emplace(L(name, index[name]), name);

		for (int i = 1; i < n; ++i) {
			const int next = q.top().first;
			ugly.push_back(next);
			while (q.top().first == next) {
				const int name = q.top().second;
				q.pop(), q.emplace(L(name, ++index[name]), name);
			}
		}
		return ugly.back();
	}
};
