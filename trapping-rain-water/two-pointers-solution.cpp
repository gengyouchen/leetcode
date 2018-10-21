class Solution {
public:
	/* time: O(n), space: O(1) */
	int trap(const vector<int>& height) {
		int globalThreshold = 0, ans = 0;
		auto L = height.begin(), R = height.end();
		while (L != R) {
			const int localThreshold = (*L < *(R - 1)) ? (*L++) : (*--R);
			globalThreshold = max(globalThreshold, localThreshold);
			ans += globalThreshold - localThreshold;
		}
		return ans;
	}
};
