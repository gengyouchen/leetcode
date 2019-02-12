class Solution {
public:
	/* time: O(1), space: O(1) */
	int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
		const long areaA = max((long)C - (long)A, 0L) * max((long)D - (long)B, 0L);
		const long areaB = max((long)G - (long)E, 0L) * max((long)H - (long)F, 0L);

		const long xBegin = max(A, E), xEnd = min(C, G);
		const long yBegin = max(B, F), yEnd = min(D, H);
		const long areaCommon = max(xEnd - xBegin, 0L) * max(yEnd - yBegin, 0L);

		return areaA + areaB - areaCommon;
	}
};
