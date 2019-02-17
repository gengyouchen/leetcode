#define P1 3
#define P2 P1 * P1
#define P4 P2 * P2
#define P8 P4 * P4
#define P16 P8 * P8
#define P19 P16 * P2 * P1

class Solution {
public:
	/* time: O(1), space: O(1) */
	bool isPowerOfThree(int n) {
		if (n <= 0)
			return false;
		return (P19 % n == 0);
	}
};
