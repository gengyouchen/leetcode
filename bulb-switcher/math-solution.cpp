class Solution {
public:
	/* time: O(1), space: O(1), assuming sqrt(x) is O(1) time */
	static int bulbSwitch(int n) {
		/*
		 * By observing # of divisor:
		 * 1st bulb: 1 -> on
		 * 2nd bulb: 1, 2 -> off
		 * 3rd bulb: 1, 3 -> off
		 * 4th bulb: 1, 2, 4 -> on
		 * 5th bulb: 1, 5 -> off
		 * 6th bulb: 1, 2, 3, 6 -> off
		 * 7th bulb: 1, 7 -> off
		 * 8th bulb: 1, 2, 4, 8 -> off
		 * 9th bulb: 1, 3, 9 -> on
		 * ...
		 *
		 * Only those square numbers will be turned on:
		 * 1*1 = 1, 2*2 = 4, 3*3 = 9, 4*4 = 16, ..., i*i <= n
		 * Therefore, i = sqrt(n)
		 */
		return sqrt(n);
	}
};
