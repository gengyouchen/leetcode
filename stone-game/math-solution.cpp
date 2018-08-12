class Solution {
public:
	/* time: O(1), space: O(1) */
	bool stoneGame(vector<int>& piles) {
		/*
		 * piles = [R[0], B[0], R[1], B[1], R[2], B[2] ... R[n/2], B[n/2]]
		 * If sum(red) > sum(black), Alex can always take all red stones.
		 * If sum(black) > sum(red), Alex can always take all black stones.
		 * Therefore, Alex can always win.
		 */
		return true;
	}
};
