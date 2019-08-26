class Counter {
private:
	unordered_map<int, int> key2count;
	int nDistinct = 0;
public:
	void add(int key) {
		if (++key2count[key] == 1)
			++nDistinct;
	};
	void remove(int key) {
		if (--key2count[key] == 0)
			key2count.erase(key), --nDistinct;
	}
	int countDistinct() const { return nDistinct; }
};

class Solution {
private:
	/* See LeetCode 340 - Longest Substring with At Most K Distinct Characters */
	static int subarraysWithAtMostKDistinct(const vector<int>& A, int K) {
		const int n = A.size();
		Counter window;
		int ans = 0, L = 0;
		for (int R = 0; R < n; ++R) {
			window.add(A[R]);
			while (window.countDistinct() > K)
				window.remove(A[L++]);
			ans += R - L + 1;
		}
		return ans;
	}
public:
	/* time: O(n), space: O(k) */
	static int subarraysWithKDistinct(const vector<int>& A, int K) {
		return subarraysWithAtMostKDistinct(A, K) - subarraysWithAtMostKDistinct(A, K - 1);
	}
};
