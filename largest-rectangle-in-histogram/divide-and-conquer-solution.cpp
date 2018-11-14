class RangeMinimumQuery {
private:
	const vector<int>& nums;
	int minNode(int i, int j) const {
		const int a = (i < nums.size()) ? nums[i] : INT_MAX;
		const int b = (j < nums.size()) ? nums[j] : INT_MAX;
		return (a < b) ? i : j;
	}
	vector<int> segTree;
public:
	RangeMinimumQuery(const vector<int>& nums) : nums(nums) {
		int nLeaf = 1;
		while (nLeaf < nums.size())
			nLeaf *= 2;
		segTree.resize(nLeaf * 2);
		iota(segTree.begin() + nLeaf, segTree.end(), 0);
		for (int x = nLeaf - 1; x; --x)
			segTree[x] = minNode(segTree[x * 2], segTree[x * 2 + 1]);
	}
	int findMin(int i, int j) const {
		assert((i >= 0) && (j >= i) && (j < nums.size()));
		if (i == j)
			return i;
		i += segTree.size() / 2, j += segTree.size() / 2;
		int ans = minNode(segTree[i], segTree[j]);
		while (i + 1 != j) {
			if (!(i % 2))
				ans = minNode(ans, segTree[i + 1]);
			if (j % 2)
				ans = minNode(ans, segTree[j - 1]);
			i /= 2, j /= 2;
		}
		return ans;
	}
};

class Solution {
private:
	typedef function<int(int, int)> F;
public:
	/* time: O(n*log(n)), space: O(n) */
	int largestRectangleArea(vector<int>& heights) {
		if (heights.empty())
			return 0;
		RangeMinimumQuery bars(heights);
		F maxArea = [&](int i, int j) {
			const int minBar = bars.findMin(i, j);
			int ans = heights[minBar] * (j - i + 1);
			if (minBar > i)
				ans = max(ans, maxArea(i, minBar - 1));
			if (minBar < j)
				ans = max(ans, maxArea(minBar + 1, j));
			return ans;
		};
		return maxArea(0, heights.size() - 1);
	}
};
