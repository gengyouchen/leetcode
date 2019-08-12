class RangeMajorityVoteQuery {
	private static class MajorityVote {
		public int num = 0, vote = 0;
	}
	private static MajorityVote merge(MajorityVote a, MajorityVote b) {
		MajorityVote ret = new MajorityVote();
		ret.num = (a.vote > b.vote) ? a.num : b.num;
		ret.vote = (a.num == b.num) ? (a.vote + b.vote) : Math.abs(a.vote - b.vote);
		return ret;
	}

	private MajorityVote[] segTree;
	public RangeMajorityVoteQuery(int[] A) {
		final int n = A.length;
		int nLeaf = 1;
		while (nLeaf < n)
			nLeaf *= 2;
		segTree = new MajorityVote[nLeaf * 2];

		for (int i = 0; i < nLeaf; ++i) {
			MajorityVote node = new MajorityVote();
			if (i < n) {
				node.num = A[i];
				node.vote = 1;
			}
			segTree[nLeaf + i] = node;
		}

		for (int x = nLeaf - 1; x > 0; --x)
			segTree[x] = merge(segTree[x * 2], segTree[x * 2 + 1]);
	}
	public int query(int i, int j) {
		final int nLeaf = segTree.length / 2;
		int x = nLeaf + i, y = nLeaf + j;

		MajorityVote ret = merge(segTree[x], segTree[y]);
		while (x / 2 != y / 2) {
			if (x % 2 == 0)
				ret = merge(ret, segTree[x + 1]);
			if (y % 2 == 1)
				ret = merge(ret, segTree[y - 1]);
			x /= 2;
			y /= 2;
		}

		if (ret.vote == 0)
			return -1; /* failed */
		return ret.num;
	}
}

class MajorityChecker {
	private RangeMajorityVoteQuery q;
	private HashMap<Integer, ArrayList<Integer>> val2idx;
	private static int lowerBound(ArrayList<Integer> A, int x) {
		int L = 0, R = A.size();
		while (L < R) {
			final int mid = L + (R - L) / 2;
			if (A.get(mid) >= x)
				R = mid;
			else
				L = mid + 1;
		}
		return L;
	}
	private static int upperBound(ArrayList<Integer> A, int x) {
		int L = 0, R = A.size();
		while (L < R) {
			final int mid = L + (R - L) / 2;
			if (A.get(mid) > x)
				R = mid;
			else
				L = mid + 1;
		}
		return L;
	}
	/* time: O(n), space: O(n) */
	public MajorityChecker(int[] arr) {
		final int n = arr.length;
		q = new RangeMajorityVoteQuery(arr);
		val2idx = new HashMap<Integer, ArrayList<Integer>>();
		for (int i = 0; i < n; ++i) {
			if (!val2idx.containsKey(arr[i]))
				val2idx.put(arr[i], new ArrayList<Integer>());
			ArrayList<Integer> idx = val2idx.get(arr[i]);
			idx.add(i);
		}
	}
	/* time: O(log(n)), space: O(1) auxiliary */
	public int query(int left, int right, int threshold) {
		final int majorityVote = q.query(left, right);
		if (majorityVote == -1)
			return -1;

		ArrayList<Integer> idx = val2idx.get(majorityVote);
		final int L = lowerBound(idx, left);
		final int R = upperBound(idx, right);
		final int count = R - L;
		if (count < threshold)
			return -1;

		return majorityVote;
	}
}
