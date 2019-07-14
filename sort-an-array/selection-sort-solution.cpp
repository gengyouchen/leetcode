class Solution {
private:
	static void selectionSort(vector<int>& A) {
		const int n = A.size();
		for (int len = 0; len < n; ++len) {
			int smallest = len;
			for (int i = len + 1; i < n; ++i) {
				if (A[i] < A[smallest])
					smallest = i;
			}
			swap(A[len], A[smallest]);
		}
	}
public:
	/* time: O(n^2), space: O(1) auxiliary (i.e. does not count input & output itself) */
	static vector<int> sortArray(vector<int>& nums) {
		selectionSort(nums);
		return nums;
	}
};
