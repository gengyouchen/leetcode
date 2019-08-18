class CountingSort {
private:
	const int low, high;
	vector<int> output, count;
public:
	CountingSort(int low, int high) : low(low), high(high), count(high - low + 1) { }
	template <class F>
	void sort(vector<int>& A, F digit) {
		const int n = A.size();
		output.resize(n);
		fill(count.begin(), count.end(), 0);

		for (int i = 0; i < n; ++i) {
			const int val = digit(A[i]) - low;
			++count[val];
		}
		partial_sum(count.begin(), count.end(), count.begin());

		for (int i = n - 1; i >= 0; --i) {
			const int val = digit(A[i]) - low;
			output[--count[val]] = A[i];
		}
		swap(output, A);
	}
};

class SuffixArray {
private:
	vector<int> SA;
public:
	SuffixArray(const string& s) : SA(s.size()) {
		const int n = s.size();
		vector<int> rank(n), output(n);
		iota(SA.begin(), SA.end(), 0);
		copy(s.begin(), s.end(), rank.begin());

		/*
		 * For simplicity, we use the prefix-doubling algorithm here, costing O(n*log(n)) time.
		 * There are other faster algorithms, such as DC3 or SA-IS, which can achieve O(n) time.
		 */
		CountingSort csort(-1, max(256, n));
		for (int len = 1; len < n; len *= 2) {
			auto leftPart = [&](int suffix) { return rank[suffix]; };
			auto rightPart = [&](int suffix) { return (suffix + len < n) ? rank[suffix + len] : -1; };

			csort.sort(SA, rightPart);
			csort.sort(SA, leftPart);

			int k = 0;
			output[SA[0]] = k;
			for (int i = 1; i < n; ++i) {
				if (leftPart(SA[i - 1]) != leftPart(SA[i]) || rightPart(SA[i - 1]) != rightPart(SA[i]))
					++k;
				output[SA[i]] = k;
			}
			swap(output, rank);

			if (k == n - 1)
				break; /* speed up: every suffix has different rank, so no need to sort further */
		}
	}
	int getSuffix(int order) const { return SA[order]; }
};

class Solution {
public:
	/* time: O(n*log(n)), space: O(n), assuming the suffix array is constructed in O(n*log(n)) time */
	static string lastSubstring(const string& s) {
		const int n = s.size();
		const SuffixArray sa(s);
		return s.substr(sa.getSuffix(n - 1));
	}
};
