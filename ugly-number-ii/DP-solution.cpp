class Solution {
public:
	/* time: O(n), space: O(n) */
	int nthUglyNumber(int n) {
		/*
		 * Use the given hint from this problem:
		 * ugly: 1,  2,    3,  4,    5,  6,    8,  9, 10, 12
		 *   L1: 2,  4,    6,  8,   10, 12, "16", 18, 20, 24
		 *   L2: 3,  6,    9, 12, "15", 18,   24, 27, 30, 36
		 *   L3: 5, 10, "15", 20,   25, 30,   40, 45, 50, 60
		 * Therefore, ugly[10] = min(16, 15, 15) = 15
		 *
		 * ugly: 1,  2,  3,    4,  5,    6,    8,  9, 10, 12, 15
		 *   L1: 2,  4,  6,    8, 10,   12, "16", 18, 20, 24, 30
		 *   L2: 3,  6,  9,   12, 15, "18",   24, 27, 30, 36, 45
		 *   L3: 5, 10, 15, "20", 25,   30,   40, 45, 50, 60, 75
		 * Therefore, ugly[11] = min(16, 18, 20) = 16
		 */
		vector<int> ugly;
		ugly.push_back(1);

		auto L1 = [&](int i) { return ugly[i] * 2; };
		auto L2 = [&](int i) { return ugly[i] * 3; };
		auto L3 = [&](int i) { return ugly[i] * 5; };

		int x = 0, y = 0, z = 0;
		for (int i = 1; i < n; ++i) {
			const int next = min(min(L1(x), L2(y)), L3(z));
			ugly.push_back(next);

			if (L1(x) == next)
				++x;
			if (L2(y) == next)
				++y;
			if (L3(z) == next)
				++z;
		}
		return ugly.back();
	}
};
