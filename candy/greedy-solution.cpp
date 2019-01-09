class Solution {
public:
	/* time: O(n), space: O(1) */
	int candy(const vector<int>& ratings) {
		if (ratings.empty())
			return 0;
		int ans = 1, nHigher = 0, nLower = 0;
		/*
		 *  ratings: 60 -> 70 -> 90 -> 95 -> 91 -> 82 -> 75 -> 70 -> 65 -> 66 ...
		 *                |-- go high ---|  |-------- go lower --------|
		 *  candies:  1 ->  2 ->  3 ->  6 ->  5 ->  4 ->  3 ->  2 ->  1 ->  2 ...
		 */
		for (int i = 1; i < ratings.size(); ++i) {
			if (ratings[i - 1] < ratings[i]) {
				if (nLower > 0)
					nHigher = nLower = 0;
				++nHigher;
				ans += 1 + nHigher;
			} else if (ratings[i - 1] > ratings[i])  {
				++nLower;
				ans += (nLower > nHigher ? 1 : 0) + nLower;
			} else {
				nHigher = nLower = 0;
				ans += 1;
			}
		}
		return ans;
	}
};
