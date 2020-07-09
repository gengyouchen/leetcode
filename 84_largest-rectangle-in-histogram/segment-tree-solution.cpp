class RangeMinimumQuery {
private:
	const vector<int>& A;
	int merge(int i, int j) const {
		const int n = A.size();
		const int a = (i < n) ? A[i] : INT_MAX;
		const int b = (j < n) ? A[j] : INT_MAX;
		return (a < b) ? i : j;
	}
	vector<int> segTree;
public:
	RangeMinimumQuery(const vector<int>& A) : A(A) {
		const int n = A.size();
		int nLeaf = 1;
		while (nLeaf < n)
			nLeaf *= 2;
		segTree.resize(nLeaf * 2);

		iota(segTree.begin() + nLeaf, segTree.end(), 0);
		for (int x = nLeaf - 1; x; --x)
			segTree[x] = merge(segTree[x * 2], segTree[x * 2 + 1]);
	}
	int query(int i, int j) const {
		const int nLeaf = segTree.size() / 2;
		int x = nLeaf + i, y = nLeaf + j, ret = merge(segTree[x], segTree[y]);
		while (x / 2 != y / 2) {
			if (!(x % 2))
				ret = merge(ret, segTree[x + 1]);
			if (y % 2)
				ret = merge(ret, segTree[y - 1]);
			x /= 2, y /= 2;
		}
		return ret;
	}
};

class Solution {
public:
	/* time: O(n*log(n)), space: O(n) */
	static int largestRectangleArea(const vector<int>& heights) {
		const int n = heights.size();
		const RangeMinimumQuery rmq(heights);

		int ans = 0;
		using F = function<void(int, int)>;
		F dfs = [&](int i, int j) {
			if (i <= j) {
				const int pivot = rmq.query(i, j);
				ans = max(ans, heights[pivot] * (j - i + 1));
				dfs(i, pivot - 1), dfs(pivot + 1, j);
			}
		};
		dfs(0, n - 1);
		return ans;
	}
};
