class Solution {
public:
	/* time: O(n*log(n)), space: O(n) */
	static int oddEvenJumps(const vector<int>& A) {
		const int n = A.size();
		vector<int> adjOdd(n), adjEven(n);
		map<int, int> val2index;
		for (int i = n - 1; i >= 0; --i) {
			auto it = val2index.lower_bound(A[i]);
			if (it != val2index.end())
				adjOdd[i] = it->second;

			it = val2index.upper_bound(A[i]);
			if (it != val2index.begin())
				--it, adjEven[i] = it->second;

			val2index[A[i]] = i;
		}

		vector<bool> goodOdd(n), goodEven(n);
		for (int i = n - 1; i >= 0; --i) {
			if (i == n - 1) {
				goodOdd[i] = goodEven[i] = true;
			} else {
				if (adjOdd[i])
					goodOdd[i] = goodEven[adjOdd[i]];
				if (adjEven[i])
					goodEven[i] = goodOdd[adjEven[i]];
			}
		}
		return count(goodOdd.begin(), goodOdd.end(), true);
	}
};
