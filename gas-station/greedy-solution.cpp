class Solution {
public:
	/* time: O(n), space: O(1) */
	int canCompleteCircuit(const vector<int>& gas, const vector<int>& cost) {
		const int n = gas.size();
		int start = 0, curr = 0, tank = 0;
		while (true) {
			tank += (gas[curr] - cost[curr]), curr = (curr + 1) % n;
			if (tank < 0) {
				/*
				 * the answer won't be in {start, start + 1, start + 2, ..., curr - 2, curr - 1},
				 * so we only need to consider re-starting from curr.
				 */
				if (curr <= start)
					break; /* new start position is looped again -> there's no answer */
				start = curr, tank = 0;
			} else if (curr == start) {
				return start;
			}
		}
		return -1; /* no answer */
	}
};
