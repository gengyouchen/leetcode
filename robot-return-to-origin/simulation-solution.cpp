class Solution {
public:
	/* time: O(n), space: O(1), where n = |moves| */
	static bool judgeCircle(const string& moves) {
		int x = 0, y = 0;
		for (char c : moves) {
			switch (c) {
			case 'U':
				++y;
				break;
			case 'D':
				--y;
				break;
			case 'L':
				--x;
				break;
			case 'R':
				++x;
				break;
			}
		}
		return !x && !y;
	}
};
