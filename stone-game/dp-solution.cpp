class Solution {
public:
	/* time: O(n^2), space: O(n) */
	bool stoneGame(vector<int>& piles) {
		auto _alex = vector<vector<int>>(2, vector<int>(piles.size()));
		auto _lee = vector<vector<int>>(2, vector<int>(piles.size()));
		auto alex = [&](int i, int j) -> int& { return _alex[i % 2][j]; };
		auto lee = [&](int i, int j) -> int& { return _lee[i % 2][j]; };

		for (int i = piles.size() - 1; i >= 0; --i) {
			for (int j = i; j < piles.size(); ++j) {
				if (i == j) {
					alex(i, j) = piles[i];
					lee(i, j) = -piles[i];
				} else {
					alex(i, j) = max(lee(i + 1, j) + piles[i], lee(i, j - 1) + piles[j]);
					lee(i, j) = min(alex(i + 1, j) - piles[i], alex(i, j - 1) - piles[j]);
				}
			}
		}
		return alex(0, piles.size() - 1) > 0;
	}
};
