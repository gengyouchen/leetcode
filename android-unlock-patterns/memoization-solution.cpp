class Solution {
public:
	/* time: O(sum(C(9, k)) for k = 1 ~ n), space: O(sum(C(9, k)) for k = 1 ~ n) */
	static int numberOfPatterns(int m, int n) {
		unordered_map<bitset<18>, int> cache;
		bitset<18> used;

		auto isValid = [&](int next, int prev) {
			if (prev == -1)
				return true;
			if (used[next])
				return false;

			const int y0 = prev / 3, x0 = prev % 3, y1 = next / 3, x1 = next % 3;
			if (y0 % 2 != y1 % 2 || x0 % 2 != x1 % 2)
				return true;

			const int mid = (prev + next) / 2;
			return used.test(mid);
		};

		using F = function<int(int, int)>;
		F backtrack = [&](int prev, int step) {
			if (step > n)
				return 0;

			if (prev != -1) {
				used.set(9 + prev);
				const auto it = cache.find(used);
				used.reset(9 + prev);
				if (it != cache.end())
					return it->second;
			}

			int count = (step >= m) ? 1 : 0;
			for (int next = 0; next < 9; ++next) {
				if (isValid(next, prev))
					used.set(next), count += backtrack(next, step + 1), used.reset(next);
			}

			if (prev != -1)
				used.set(9 + prev), cache[used] = count, used.reset(9 + prev);
			return count;
		};
		return backtrack(-1, 0);
	}
};
