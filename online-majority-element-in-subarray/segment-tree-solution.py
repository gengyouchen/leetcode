class RangeMajorityVoteQuery:
	# Use Boyer–Moore majority vote algorithm. See LeetCode 169 - Majority Element
	class MajorityVote:
		num = 0
		vote = 0
	def merge(self, a: MajorityVote, b: MajorityVote) -> MajorityVote:
		ret = self.MajorityVote()
		ret.num = a.num if a.vote > b.vote else b.num
		ret.vote = a.vote + b.vote if a.num == b.num else abs(a.vote - b.vote)
		return ret;

	# Use Segment Tree. See LeetCode 307 - Range Sum Query - Mutable
	def __init__(self, A: List[int]):
		self.segTree = []
		nLeaf = 1;
		while nLeaf < len(A):
			nLeaf *= 2;
		for i in range(nLeaf * 2):
			node = self.MajorityVote()
			self.segTree.append(node)

		for i in range(len(A)):
			node = self.segTree[nLeaf + i]
			node.num, node.vote = A[i], 1

		for x in range(nLeaf - 1, 0, -1):
			self.segTree[x] = self.merge(self.segTree[x * 2], self.segTree[x * 2 + 1])

	def query(self, i: int, j: int) -> int:
		nLeaf = len(self.segTree) // 2
		x, y = nLeaf + i, nLeaf + j

		ret = self.merge(self.segTree[x], self.segTree[y]);
		while x // 2 != y // 2:
			if x % 2 == 0:
				ret = self.merge(ret, self.segTree[x + 1])
			if y % 2 == 1:
				ret = self.merge(ret, self.segTree[y - 1])
			x //= 2
			y //= 2

		if ret.vote == 0:
			return -1; # failed
		return ret.num

class MajorityChecker:
	# time: O(n), space: O(1) auxiliary (i.e. does not count tree and hash table itself)
	def __init__(self, arr: List[int]):
		self.q = RangeMajorityVoteQuery(arr)
		self.val2idx = {}
		for i in range(len(arr)):
			self.val2idx.setdefault(arr[i], []).append(i)

	# time: O(log(n)), space: O(1) auxiliary (i.e. does not count tree and hash table itself)
	def query(self, left: int, right: int, threshold: int) -> int:
		majorityVote = self.q.query(left, right)
		if majorityVote == -1:
			return -1
		idx = self.val2idx.get(majorityVote)
		L = bisect.bisect_left(idx, left)
		R = bisect.bisect_right(idx, right)
		count = R - L
		if count < threshold:
			return -1
		return majorityVote
