class CountingSort {
private:
	const int low, high;
	vector<int> tmp, count;
public:
	CountingSort(int low, int high) : low(low), high(high), count(high - low + 1) { }
	template <class F>
	void sort(vector<int>& A, F digit) {
		const int n = A.size();
		tmp.resize(n);
		fill(count.begin(), count.end(), 0);

		for (int i = 0; i < n; ++i) {
			const int val = digit(A[i]) - low;
			++count[val];
		}
		partial_sum(count.begin(), count.end(), count.begin());

		for (int i = n - 1; i >= 0; --i) {
			const int val = digit(A[i]) - low;
			tmp[--count[val]] = A[i];
		}
		swap(tmp, A);
	}
};

class Solution {
private:
	static vector<int> getSuffixArray(const string& str) {
		const int n = str.size();
		vector<int> SA(n), rank(n), tmp(n);
		iota(SA.begin(), SA.end(), 0);
		copy(str.begin(), str.end(), rank.begin());

		/*
		 * For simplicity, we use the prefix-doubling algorithm in O(n*log(n)) time.
		 * There are other faster algorithms, such as DC3 or SA-IS, which can achieve O(n) time.
		 */
		CountingSort cs(-1, max(256, n));
		for (int len = 1; len < n; len *= 2) {
			auto leftPart = [&](int suffix) { return rank[suffix]; };
			auto rightPart = [&](int suffix) { return (suffix + len < n) ? rank[suffix + len] : -1; };

			cs.sort(SA, rightPart);
			cs.sort(SA, leftPart);

			int k = 0;
			tmp[SA[0]] = k;
			for (int i = 1; i < n; ++i) {
				if (leftPart(SA[i - 1]) != leftPart(SA[i]) || rightPart(SA[i - 1]) != rightPart(SA[i]))
					++k;
				tmp[SA[i]] = k;
			}
			swap(tmp, rank);

			if (k == n - 1)
				break; /* speed up: every suffix has different rank, so no need to sort further */
		}
		return SA;
	}
	static vector<int> getLCPArray(const string& str, const vector<int>& SA) {
		const int n = str.size();
		vector<int> rank(n);
		for (int i = 0; i < n; i++)
			rank[SA[i]] = i;

		/* Use Kasai's algorithm to build LCP array in O(n) time */
		vector<int> LCP(n);
		int len = 0;
		for (int suffix = 0; suffix < n; suffix++) {
			const int i = rank[suffix], j = i + 1;
			if (i == n - 1) {
				len = 0;
				continue;
			}
			const int adj = SA[j];
			while (suffix + len < n && adj + len < n && str[suffix + len] == str[adj + len])
				++len;
			LCP[i] = len;
			if (len > 0)
				--len;
		}
		return LCP;
	}
public:
	/* time: O(n*log(n)), space: O(n), assuming the suffix array is constructed in O(n*log(n)) time */
	static string longestDupSubstring(const string& S) {
		const auto SA = getSuffixArray(S), LCP = getLCPArray(S, SA);
		const int n = SA.size();

		int suffix = 0, len = 0;
		for (int i = 0; i < n; ++i) {
			if (LCP[i] > len)
				suffix = SA[i], len = LCP[i];
		}
		return S.substr(suffix, len);
	}
};
