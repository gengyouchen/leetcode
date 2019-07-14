class Solution {
private:
	static void merge(vector<int>& out, vector<int>& A, int L, int mid, int R) {
		int i = L, j = mid + 1;
		for (int k = L; k <= R; ++k) {
			if (i > mid)
				out[k] = A[j++];
			else if (j > R)
				out[k] = A[i++];
			else if (A[i] < A[j])
				out[k] = A[i++];
			else
				out[k] = A[j++];
		}
		for (int k = L; k <= R; ++k)
			A[k] = out[k];
	}
	static void mergeSort(vector<int>& out, vector<int>& A, int L, int R) {
		if (L == R) {
			out[L] = A[L];
		} else if (L < R) {
			const int mid = L + (R - L) / 2;
			mergeSort(out, A, L, mid), mergeSort(out, A, mid + 1, R);
			merge(out, A, L, mid, R);
		}
	}
public:
	/* time: O(n*log(n)), space: O(n) */
	static vector<int> sortArray(vector<int>& nums) {
		const int n = nums.size();
		vector<int> ans(n);
		mergeSort(ans, nums, 0, n - 1);
		return ans;
	}
};
