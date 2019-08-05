class Solution {
public:
	/* time: O(n), space: O(n), where n = len(high) */
	static int strobogrammaticInRange(const string& low, const string& high) {
		if (low.size() > high.size())
			return 0;
		if (low.size() == high.size() && low > high)
			return 0;

		const string center = "018", MSB = "1689", other = "01689";
		char h[256] = {};
		h['0'] = '0', h['1'] = '1', h['6'] = '9', h['8'] = '8', h['9'] = '6';

		const int n = high.size();
		vector<long long> dp(n + 1);
		for (int len = 0; len <= n; ++len) {
			if (len == 0)
				dp[len] = 1;
			else if (len == 1)
				dp[len] = center.size();
			else
				dp[len] = dp[len - 2] * other.size();
		}

		auto countShorter = [&](const auto& s) {
			long long count = 0;
			for (int len = 0; len < s.size(); ++len)
				count += (len <= 1) ? dp[len] : (dp[len] * MSB.size() / other.size());
			return count;
		};

		auto countSameLength = [&](const auto& s) {
			long long count = 0;
			int i = 0, j = s.size() - 1;

			for (; i <= j; ++i, --j) {
				const int len = j - i + 1;
				bool hasSubProblem = false;
				for (char c : (i == j) ? center : (i == 0) ? MSB : other) {
					if (c < s[i])
						count += (i == j) ? 1 : dp[len - 2];
					if (c == s[i])
						hasSubProblem = true;
				}
				if (!hasSubProblem)
					return count;
			}

			for (; i < s.size(); ++i, --j) {
				const char c = h[s[j]];
				if (c < s[i])
					return count + 1;
				if (c > s[i])
					return count;
			}
			return count + 1;
		};

		auto isStrobogrammatic = [&](const auto& s) {
			for (int i = 0, j = s.size() - 1; i <= j; ++i, --j) {
				if (h[s[i]] != s[j])
					return 0; /* No */
			}
			return 1; /* Yes */
		};

		auto countLessEqual = [&](const auto& s) { return countShorter(s) + countSameLength(s); };
		auto countLess = [&](const auto& s) { return countLessEqual(s) - isStrobogrammatic(s); };
		return countLessEqual(high) - countLess(low);
	}
};
