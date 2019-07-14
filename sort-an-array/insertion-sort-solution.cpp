class Solution {
private:
	static void insertionSort(vector<int>& A) {
		const int n = A.size();
		for (int len = 1; len < n; ++len) {
			const int target = A[len];
			int prev = len - 1;
			while (prev >= 0 && A[prev] > target)
				A[prev + 1] = A[prev], --prev;
			A[prev + 1] = target;
		}
	}
public:
	/* time: O(n^2), space: O(1) auxiliary (i.e. does not count input & output itself) */
	static vector<int> sortArray(vector<int>& nums) {
		insertionSort(nums);
		return nums;
	}
};
