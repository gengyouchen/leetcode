class Solution {
private:
	static int forwardMatch(const string& S, int L, const string& T) {
		const int n = S.size(), m = T.size();
		int R = L;
		for (int i = 0; i < m; ++i, ++R) {
			while (R < n && S[R] != T[i])
				++R;
			if (R == n)
				return -1; /* failed */
		}
		return --R; /* succeed */
	}
	static int backwardMatch(const string& S, int R, const string& T) {
		const int n = S.size(), m = T.size();
		int L = R;
		for (int i = m - 1; i >= 0; --i, --L) {
			while (L >= 0 && S[L] != T[i])
				--L;
			if (L < 0)
				return -1; /* failed */
		}
		return ++L; /* succeed */
	}
public:
	/*
	 * time: O(n*m), space: O(1), where n = |S|, m = |T|
	 *
	 * Why O(n*m) instead of O(n^2)?
	 * Ans: each character i in S will be scanned at most 2*m times.
	 *
	 * <Proof>
	 * If before a forwardMatch+backwardMatch, S[i] is matched to T[j],
	 * then after a forwardMatch+backwardMatch, S[i] will be matched to T[k], where k < j.
	 *
	 * Therefore, after at most m times of forwardMatch+backwardMatch,
	 * S[i] will be rolled out (i.e L will exceed i).
	 */
	static string minWindow(const string& S, const string& T) {
		const int n = S.size(), m = T.size();

		int L = 0, ansPos = -1, ansLen = INT_MAX;
		while (L < n) {
			const int R = forwardMatch(S, L, T);
			if (R == -1)
				break;

			const int bestL = backwardMatch(S, R, T);
			if (bestL == -1)
				break;

			const int len = R - bestL + 1;
			if (len < ansLen)
				ansPos = bestL, ansLen = len;
			L = bestL + 1;
		}
		return (ansPos == -1) ? "" : S.substr(ansPos, ansLen);
	}
};
