class Solution {
public:
	/*
	 * time: O(n), space: O(1)
	 *
	 * <Greedy-choice Property>
	 * For all reachable nodes 0 <= i <= k,
	 * selecting the i such that (i + nums[i]) is maximized
	 * can always yield a global optima solution
	 * (i.e. can reach to the farthest position)
	 *
	 * <Proof>
	 * If there's a global optimal where the above i is not in the jump path...
	 * there're must be another node i' in the optimal jump path such that:
	 * k < (i' + nums[i']) < (i + nums[i])
	 *
	 * Therefore, in the jump path, we can safetly replace node i' with node i
	 * because if node i' can jump to node j, then node i can also jump to node j:
	 * Optimal jump path: a -> b -> c -> ... -> i' -> j -> ... -> z
	 * Replaced jump path: a -> b -> c -> ... -> i -> j -> ... -> z
	 *
	 * Therefore, selecting node i can also yield a global optima solution
	 */
	int jump(vector<int>& nums) {
		if (nums.size() <= 1)
			return 0;

		int reached = nums[0], discovered = 0, ans = 0;
		for (int i = 0; i < nums.size(); ++i) {
			discovered = max(discovered, i + nums[i]);
			if (i == reached || i == nums.size() - 1)
				reached = discovered, discovered = 0, ++ans;
		}
		return ans;
	}
};
