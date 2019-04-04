class Codec {
public:
	/*
	 * time: O(n), space: O(1) auxiliary (i.e. does not count output itself),
	 * where n = total # of chars in the given input strings
	 */
	static string encode(const vector<string>& strs) {
		/*
		 * The string may contain any possible characters out of 256 valid ascii characters,
		 * so we cannot use a dedicated character for representing the beginning of the string.
		 *
		 * Our solution is to combine each 8 bytes raw data with an additional 8-bit mask,
		 * which represents which bytes are the beginning of the strings.
		 */
		string ans;
		bitset<8> mask;
		char buf[8];
		int count = 0;
		auto flush = [&]() {
			if (count > 0) {
				ans.push_back((unsigned char)mask.to_ulong());
				for (int i = 0; i < count; ++i)
					ans.push_back(buf[i]);
				mask.reset(), count = 0;
			}
		};
		auto createString = [&]() {
			mask.set(count++);
			if (count == 8)
				flush();
		};
		auto appendChar = [&](char c) {
			buf[count++] = c;
			if (count == 8)
				flush();
		};
		for (const string& str : strs) {
			createString();
			for (char c : str)
				appendChar(c);
		}
		flush();
		return ans;
	}

	/* time: O(n), space: O(1) auxiliary (i.e. does not count output itself) */
	static vector<string> decode(const string& s) {
		vector<string> ans;
		bitset<8> mask;
		int count = 8;
		for (char c : s) {
			if (count == 8) {
				mask = bitset<8>(c), count = 0;
			} else {
				if (mask.test(count++))
					ans.emplace_back();
				else
					ans.back().push_back(c);
			}
		}
		return ans;
	}
};
