class Solution {
private:
	static void bubbleSort(vector<int>& A) {
		const int n = A.size();
		for (int len = 0; len <= n - 2; ++len) {
			for (int i = n - 2; i >= len; --i) {
				if (A[i] > A[i + 1])
					swap(A[i], A[i + 1]);
			}
		}
	}
public:
	/* time: O(n^2), space: O(1) auxiliary (i.e. does not count input & output itself) */
	static vector<int> sortArray(vector<int>& nums) {
		bubbleSort(nums);
		return nums;
	}
};
