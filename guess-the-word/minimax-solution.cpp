class Solution {
private:
	static int match(const string& a, const string& b) {
		int count = 0;
		for (int k = 0; k < 6; ++k) {
			if (a[k] == b[k])
				++count;
		}
		return count;
	}
public:
	/*
	 * time: O(n^2 * step), space: O(n),
	 * where step = log(n), assuming the input wordlist is random enough
	 */
	static void findSecretWord(const vector<string>& wordlist, Master& master) {
		const int n = wordlist.size();
		vector<vector<int>> d(n, vector<int>(n));
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j)
				d[i][j] = match(wordlist[i], wordlist[j]);
		}

		unordered_set<int> candidates;
		for (int i = 0; i < n; ++i)
			candidates.insert(i);

		auto pick = [&]() {
			int best = -1, bestSize = INT_MAX;
			/*
			 * Consider picking any word from the entire wordlist, not just from the candidates set.
			 * If a word can help us eliminate more candidates, pick it even if it's not the candidate.
			 */
			for (int curr = 0; curr < n; ++curr) {
				array<int, 7> size = {};
				for (int next : candidates) {
					if (next != curr)
						++size[d[curr][next]];
				}
				const int maxSize = *max_element(size.begin(), size.end());
				if (maxSize < bestSize)
					bestSize = maxSize, best = curr;
			}
			return best;
		};

		for (int i = 0; i < 10; ++i) {
			const int curr = pick(), count = master.guess(wordlist[curr]);
			if (count == 6)
				return;

			unordered_set<int> nextCandidates;
			for (int next : candidates) {
				if (d[curr][next] == count)
					nextCandidates.insert(next);
			}
			candidates = move(nextCandidates);
		}
	}
};
