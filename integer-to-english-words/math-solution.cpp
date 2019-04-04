class Solution {
public:
	/* time: O(log(n)), space: O(1) auxiliary (i.e. does not count output itself) */
	static string numberToWords(int num) {
		static const unordered_map<int, string> words {
			{0, "Zero"},

			{1, "One"}, {2, "Two"}, {3, "Three"},
			{4, "Four"}, {5, "Five"}, {6, "Six"},
			{7, "Seven"}, {8, "Eight"}, {9, "Nine"},

			{10, "Ten"}, {20, "Twenty"}, {30, "Thirty"},
			{40, "Forty"}, {50, "Fifty"}, {60, "Sixty"},
			{70, "Seventy"}, {80, "Eighty"}, {90, "Ninety"},

			{11, "Eleven"}, {12, "Twelve"}, {13, "Thirteen"},
			{14, "Fourteen"}, {15, "Fifteen"}, {16, "Sixteen"},
			{17, "Seventeen"}, {18, "Eighteen"}, {19, "Nineteen"}
		};

		if (num <= 20)
			return words.at(num);
		if (num < 100) {
			const int onePart = num % 10, tenPart = num - onePart;
			if (!onePart)
				return words.at(tenPart);
			return words.at(tenPart) + ' ' + words.at(onePart);
		}
		if (num < 1000) {
			const int nHundred = num / 100, rest = num % 100;
			if (!rest)
				return words.at(nHundred) + " Hundred";
			return words.at(nHundred) + " Hundred " + numberToWords(rest);
		}

		string ans;
		const int nBillion = num / 1000000000;
		num %= 1000000000;
		if (nBillion)
			ans = numberToWords(nBillion) + " Billion";

		const int nMillion = num / 1000000;
		num %= 1000000;
		if (nMillion) {
			if (!ans.empty())
				ans.push_back(' ');
			ans += numberToWords(nMillion) + " Million";
		}

		const int nThousand = num / 1000;
		num %= 1000;
		if (nThousand) {
			if (!ans.empty())
				ans.push_back(' ');
			ans += numberToWords(nThousand) + " Thousand";
		}

		if (num) {
			if (!ans.empty())
				ans.push_back(' ');
			ans += numberToWords(num);
		}
		return ans;
	}
};
