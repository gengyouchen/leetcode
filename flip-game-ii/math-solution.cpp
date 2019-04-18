class Solution {
private:
	/*
	 * Define mex(A) as the first missing non-negative number in A
	 * See https://en.wikipedia.org/wiki/Mex_(mathematics)
	 */
	static int mex(vector<int>& A) {
		const int n = A.size();
		for (int i = 0; i < n; ++i) {
			while (A[i] != i) {
				const int j = A[i];
				if (j < 0 || j >= n || A[i] == A[j])
					break;
				swap(A[i], A[j]);
			}
		}
		for (int i = 0; i < n; ++i) {
			if (A[i] != i)
				return i;
		}
		return n;
	}
public:
	/* time: O(n^2), space: O(n) */
	static bool canWin(const string& s) {
		vector<int> games;
		int count = 0, maxLen = 0;
		for (char c : s) {
			if (c == '+')
				++count;
			else
				games.push_back(count), maxLen = max(maxLen, count), count = 0;
		}
		if (count)
			games.push_back(count), maxLen = max(maxLen, count);

		/*
		 * Because this is an impartial game,
		 * we can always use Sprague–Grundy theorem to convert each game state into a nimber:
		 * https://leetcode.com/problems/flip-game-ii/discuss/73954/Theory-matters-from-Backtracking(128ms)-to-DP-(0ms)
		 *
		 * If you can read Chinese, this is one of the best explanation:
		 * https://zhuanlan.zhihu.com/p/20611132
		 */
		vector<int> nimber(maxLen + 1);
		for (int len = 0; len <= maxLen; ++len) {
			vector<int> nextStates;
			for (int i = 0; i <= len - 2; ++i)
				nextStates.push_back(nimber[i] ^ nimber[len - i - 2]);
			nimber[len] = mex(nextStates);
		}

		int ans = 0;
		for (int len : games)
			ans ^= nimber[len];
		return ans;
	}
};
