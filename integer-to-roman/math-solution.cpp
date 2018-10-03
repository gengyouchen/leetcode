class Solution {
public:
	/* time: O(1), space: O(1) */
	string intToRoman(int num) {
		string ans;
		ans.resize(4 * 4);
		int out = 0;

		auto dump = [&](int digit, char ten, char five, char one) {
			digit %= 10;
			if (digit == 9) {
				ans[out++] = one;
				ans[out++] = ten;
			} else if (digit == 4) {
				ans[out++] = one;
				ans[out++] = five;
			} else {
				if (digit >= 5)
					digit -= 5, ans[out++] = five;
				for (int i = 0; i < digit; ++i)
					ans[out++] = one;
			}
		};
		dump(num / 1000, '?', '?', 'M');
		dump(num / 100, 'M', 'D', 'C');
		dump(num / 10, 'C', 'L', 'X');
		dump(num / 1, 'X', 'V', 'I');

		ans.resize(out);
		return ans;
	}
};
