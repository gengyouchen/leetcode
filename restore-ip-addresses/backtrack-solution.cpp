class Solution {
private:
	typedef string::const_iterator I;
	typedef function<void(I, I)> F;
public:
	/*
	 * time: O(b ^ k), space: O(b * k) auxiliary (i.e. does not count output itself)
	 * where b = log(256) = 3, k = 4
	 */
	vector<string> restoreIpAddresses(const string& s) {
		vector<string> ans, buf;
		F backtrack = [&](auto first, auto last) {
			if (buf.size() == 4) {
				if (first == last)
					ans.push_back(buf[0] + "." + buf[1] + "." + buf[2] + "." + buf[3]);
				return;
			}
			int num = 0;
			for (auto it = first; it != last; ++it) {
				if (it != first && num == 0)
					break;
				num = num * 10 + *it - '0';
				if (num >= 256)
					break;
				buf.emplace_back(first, it + 1);
				backtrack(it + 1, last);
				buf.pop_back();
			}
		};
		backtrack(s.begin(), s.end());
		return ans;
	}
};
