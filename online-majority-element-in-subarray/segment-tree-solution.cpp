class RangeMajorityVoteQuery {
private:
	/* Use Boyer–Moore majority vote algorithm. See LeetCode 169 - Majority Element */
	struct MajorityVote { int num, vote; };
	static MajorityVote summarize(const MajorityVote& a, const MajorityVote& b) {
		MajorityVote ret;
		ret.num = (a.vote > b.vote) ? a.num : b.num;
		ret.vote = (a.num == b.num) ? (a.vote + b.vote) : abs(a.vote - b.vote);
		return ret;
	}

	/* Use Segment Tree. See LeetCode 307 - Range Sum Query - Mutable */
	vector<MajorityVote> segTree;
public:
	RangeMajorityVoteQuery(const vector<int>& A) {
		const int n = A.size();
		int nLeaf = 1;
		while (nLeaf < n)
			nLeaf *= 2;
		segTree.resize(nLeaf * 2);

		for (int i = 0; i < n; ++i)
			segTree[nLeaf + i] = {A[i], 1};

		for (int x = nLeaf - 1; x > 0; --x)
			segTree[x] = summarize(segTree[x * 2], segTree[x * 2 + 1]);
	}
	int query(int i, int j) const {
		const int nLeaf = segTree.size() / 2;
		int x = nLeaf + i, y = nLeaf + j;

		auto ret = summarize(segTree[x], segTree[y]);
		while (x / 2 != y / 2) {
			if (!(x % 2))
				ret = summarize(ret, segTree[x + 1]);
			if (y % 2)
				ret = summarize(ret, segTree[y - 1]);
			x /= 2, y /= 2;
		}

		if (!ret.vote)
			return -1; /* failed */
		return ret.num;
	}
};

class MajorityChecker {
private:
	RangeMajorityVoteQuery q;
	unordered_map<int, vector<int>> val2idx;
public:
	/* time: O(n), space: O(1) auxiliary (i.e. does not count tree and hash table itself) */
	MajorityChecker(const vector<int>& arr) : q(arr) {
		const int n = arr.size();
		for (int i = 0; i < n; ++i)
			val2idx[arr[i]].push_back(i);
	}

	/* time: O(log(n)), space: O(1) auxiliary (i.e. does not count tree and hash table itself) */
	int query(int left, int right, int threshold) const {
		const int majorityVote = q.query(left, right);
		if (majorityVote == -1)
			return -1;

		const auto& idx = val2idx.at(majorityVote);
		const auto L = lower_bound(idx.begin(), idx.end(), left);
		const auto R = upper_bound(idx.begin(), idx.end(), right);
		const int count = distance(L, R);
		if (count < threshold)
			return -1;

		return majorityVote;
	}
};
