class Solution {
private:
	typedef function<void(int)> F;
public:
	/* time: O(n * 2^n), space: O(n) auxiliary (i.e. does not count output itself) */
	static vector<string> generateAbbreviations(const string& word) {
		const int n = word.size();
		vector<string> ans;
		vector<int> buf;
		F backtrack = [&](int step) {
			if (step == n) {
				ans.emplace_back();
				int out = 0;
				for (int i : buf) {
					if (i == 0)
						ans.back() += word[out++];
					else
						ans.back() += to_string(i), out += i;
				}
			} else {
				if (buf.empty() || buf.back() == 0)
					buf.push_back(1), backtrack(step + 1), buf.pop_back();
				else
					++buf.back(), backtrack(step + 1), --buf.back();
				buf.push_back(0), backtrack(step + 1), buf.pop_back();
			}
		};
		backtrack(0);
		return ans;
	}
};
