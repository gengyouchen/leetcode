class Solution {
private:
	/*
	 * <Greedy-choice Property>
	 * Assume sortedInput = [ a <= ... <= b <= ... <= c <= ... <= d ]
	 * If (a + d) <= binSize,
	 * putting a + d into the same bin always achieves a global optimal.
	 *
	 * <Proof>
	 * If there's a global optimal where a + d is not in the same bin...
	 *
	 * Assuming a + c are in the same bin, and b + d are in the same bin,
	 * we can exchange c and d without violating binSize limit:
	 * (a + d) <= (b + d) <= binSize because a <= b
	 * (b + c) <= (b + d) <= binSize because c <= d
	 *
	 * Assuming a + b are in the same bin, and c + d are in the same bin,
	 * we can exchange c and d without violating binSize limit:
	 * (a + d) <= (c + d) <= binSize because a <= c
	 * (b + c) <= (c + d) <= binSize because b <= d
	 *
	 * Therefore,
	 * if there's a global optimal where a + d is not in the same bin,
	 * putting a + d is in the same bin is also a global optimal.
	 */
	template <class I, class T>
	int sortedTwoSumBin(I first, I last, T binSize) {
		int binCount = 0;
		while (last - first > 1) {
			T sum = *first + *(last - 1);
			if (sum <= binSize)
				++first, --last, ++binCount;
			else
				--last, ++binCount;
		}
		if (first != last)
			++first, ++binCount;
		return binCount;
	}
public:
	/* time: O(n*log(n)), space: O(1) auxiliary (i.e. does not count input itself) */
	int numRescueBoats(vector<int>& people, int limit) {
		make_heap(people.begin(), people.end());
		sort_heap(people.begin(), people.end());
		return sortedTwoSumBin(people.begin(), people.end(), limit);
	}
};
