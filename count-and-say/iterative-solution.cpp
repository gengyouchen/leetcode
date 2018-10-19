class Solution {
public:
	/*
	 * time: O(1.3 ^ n), space: O(1.3 ^ n)
	 *
	 * In mathematics, this is called the Look-and-say sequence,
	 *    or the Conway sequence, or the Morris Number Sequence.
	 *
	 * Conway proved that when n is large (i.e. n approaches infinity),
	 *    len(countAndSay(n)) / len(countAndSay(n - 1)) = 1.303577...
	 */
	string countAndSay(int n) {
		auto runLengthEncode = [](const string& s) {
			string out = "";
			char c = s[0];
			int len = 1;
			for (auto it = s.begin() + 1; it != s.end(); ++it)
				if (*it == c)
					++len;
				else {
					out += ('0' + len);
					out += c;
					c = *it, len = 1;
				}
			out += ('0' + len);
			out += c;
			return out;
		};

		string ans = "1";
		for (int i = 1; i < n; ++i)
			ans = runLengthEncode(ans);
		return ans;
	}
};
