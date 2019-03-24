class Solution {
public:
	/* time: O(1), space: O(1) */
	int addDigits(int num) {
		/*
		 * In mathematics, this is called the Digitial Root.
		 * See https://en.wikipedia.org/wiki/Digital_root
		 */
		if (num % 9)
			return num % 9;
		else if (!num)
			return 0;
		else
			return 9;
	}
};
