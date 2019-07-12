class Solution {
private:
	/* See CLRS textbook 7.3: A randomized version of quicksort */
	static int partition(vector<int>& A, int L, int R) {
		swap(A[L + rand() % (R - L + 1)], A[R]);
		/* invariant: all items in [L, i] must < A[R] */
		int i = L - 1;
		for (int j = L; j < R; ++j) {
			if (A[j] < A[R])
				swap(A[++i], A[j]);
		}
		swap(A[i + 1], A[R]);
		return i + 1;
	}
	static void quicksort(vector<int>& A, int L, int R) {
		if (L < R) {
			const int pivot = partition(A, L, R);
			quicksort(A, L, pivot - 1), quicksort(A, pivot + 1, R);
		}
	}
public:
	/* time: O(n*log(n)), space: O(log(n)) auxiliary (i.e. does not count input & output itself) */
	static vector<int> sortArray(vector<int>& nums) {
		const int n = nums.size();
		quicksort(nums, 0, n - 1);
		return nums;
	}
};
