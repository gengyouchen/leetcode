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
	 * 0 <= i' <= k < (i' + nums[i']) < (i + nums[i])
	 *
	 * Therefore, in the jump path, we can safetly replace node i' with node i
	 * Optimal jump path: a -> b -> c -> ... -> i' -> j -> ... -> z
	 * Replaced jump path: a -> b -> c -> ... -> i -> j -> ... -> z
	 * because if node i' can jump to node j, then node i can also jump to node j
	 *
	 * Therefore, selecting node i can also yield a global optima solution
	 */
	bool canJump(vector<int>& nums) {
		if (nums.empty())
			return true;

		int reached = nums[0];
		for (int i = 0; i < nums.size() && i <= reached; ++i)
			reached = max(reached, i + nums[i]);
		return reached >= nums.size() - 1;
	}
};
