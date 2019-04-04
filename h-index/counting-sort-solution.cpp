class Solution {
public:
	/* time: O(n), space: O(n) */
	static int hIndex(const vector<int>& citations) {
		const int n = citations.size();
		vector<int> nPaper(n + 1);
		for (int nCitation : citations)
			++nPaper[min(nCitation, n)];
		partial_sum(nPaper.rbegin(), nPaper.rend(), nPaper.rbegin());

		for (int nCitation = n; nCitation >= 0; --nCitation) {
			if (nPaper[nCitation] >= nCitation)
				return nCitation;
		}
		return 0;
	}
};
