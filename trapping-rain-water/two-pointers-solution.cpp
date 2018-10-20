class Solution {
public:
	/* time: O(n), space: O(1) */
	int trap(vector<int>& height) {
		int outsideTrapLevel = 0, ans = 0;
		auto L = height.begin(), R = height.end(); /* inside area: [L, R) */
		while (L != R)
			if (*L < *(R - 1)) {
				outsideTrapLevel = max(outsideTrapLevel, *L);
				ans += outsideTrapLevel - *L;
				++L;
			} else {
				outsideTrapLevel = max(outsideTrapLevel, *(R - 1));
				ans += outsideTrapLevel - *(R - 1);
				--R;
			}
		return ans;
	}
};
