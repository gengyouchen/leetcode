class Solution {
public:
	/* time: O(n), space: O(n), where n = length of high number string */
	int strobogrammaticInRange(const string& low, const string& high) {
		const string center = "018", MSB = "1689", other = "01689";
		char h[256] = {};
		h['0'] = '0', h['1'] = '1', h['6'] = '9', h['8'] = '8', h['9'] = '6';

		const int n = high.size();
		vector<long> dp(n + 1);
		for (int i = 0; i <= n; ++i) {
			if (i == 0)
				dp[i] = 1;
			else if (i == 1)
				dp[i] = center.size();
			else
				dp[i] = dp[i - 2] * other.size();
		}

		auto countShorter = [&](const string& maxNum) -> long {
			const int w = maxNum.size();
			long count = 0;
			for (int i = 1; i < w; ++i) {
				if (i == 1)
					count += dp[i];
				else
					count += dp[i] * MSB.size() / other.size();
			}
			return count;
		};

		auto countSameLength = [&](const string& maxNum) -> long {
			const int w = maxNum.size();
			int i = 0, j = w - 1;
			long count = 0;
			bool validItself = true;
			while (i <= j) {
				const int len = j - i + 1;
				bool hasSubProblem = false;
				for (char c : (i == j) ? center : (i == 0) ? MSB : other) {
					if (c < maxNum[i])
						count += (i == j) ? 1 : dp[len - 2];
					else if (c == maxNum[i])
						hasSubProblem = true;
				}
				if (!hasSubProblem)
					return count;

				if (h[maxNum[i]] > maxNum[j])
					validItself = false;
				--j, ++i;
			}

			if (validItself)
				++count;
			return count;
		};

		auto isStrobogrammatic = [&](const string& num) -> bool {
			const int w = num.size();
			int i = 0, j = w - 1;
			while (i <= j) {
				if (h[num[i]] != num[j])
					return false;
				++i, --j;
			}
			return true;
		};

		auto countLess = [&](const string& num) -> long {
			return countShorter(num) + countSameLength(num) - (isStrobogrammatic(num) ? 1 : 0);
		};
		auto countLessEqual = [&](const string& num) -> long {
			return countShorter(num) + countSameLength(num);
		};
		return max(countLessEqual(high) - countLess(low), (long)0);
	}
};
