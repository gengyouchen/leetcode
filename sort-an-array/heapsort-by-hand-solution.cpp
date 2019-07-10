class Solution {
private:
#define LEFT(x) ((x) * 2 + 1)
#define RIGHT(x) ((x) * 2 + 2)
#define PARENT(x) (((x) - 1) / 2)
	/* See CLRS textbook 6.2: Maintaining the heap property */
	static void maxHeapify(vector<int>& A, int x, int n) {
		while (x < n) {
			int largest = x;
			if (LEFT(x) < n && A[LEFT(x)] > A[largest])
				largest = LEFT(x);
			if (RIGHT(x) < n && A[RIGHT(x)] > A[largest])
				largest = RIGHT(x);
			if (largest == x)
				break;
			swap(A[largest], A[x]), x = largest;
		}
	}
	/* See CLRS textbook 6.3: Building a heap */
	static void buildMaxHeap(vector<int>& A) {
		const int n = A.size();
		for (int x = PARENT(n - 1); x >= 0; --x)
			maxHeapify(A, x, n);
	}
	/* See CLRS textbook 6.4: The heapsort algorithm */
	static void heapsort(vector<int>& A) {
		buildMaxHeap(A);
		for (int n = A.size(); n > 1; --n)
			swap(A[0], A[n - 1]), maxHeapify(A, 0, n - 1);
	}
#undef LEFT
#undef RIGHT
#undef PARENT
public:
	/* time: O(n*log(n)), space: O(1) auxiliary (i.e. does not count input & output itself) */
	static vector<int> sortArray(vector<int>& nums) {
		heapsort(nums);
		return nums;
	}
};
