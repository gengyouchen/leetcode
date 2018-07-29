class Solution {
private:
	template <class I, class F>
	I findFirstTrue(I first, I last, F cond) {
		while (first != last) {
			I mid = first + (last - first) / 2;
			if (cond(mid))
				last = mid;
			else
				first = mid + 1;
		}
		return first;
	}
public:
	/* time: O(N*log(max(pile))), space: O(1) */
	int minEatingSpeed(vector<int>& piles, int H) {
		int maxPile = *max_element(piles.begin(), piles.end());
		return findFirstTrue(1, maxPile, [&](int K) {
			int nHours = 0;
			for (int pile : piles) {
				nHours += (pile - 1) / K + 1;
				if (nHours > H)
					return false;
			}
			return true;
		});
	}
};
