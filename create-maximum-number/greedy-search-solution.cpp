class RangeMinimumQuery {
private:
	vector<vector<int>> nextIndex;
public:
	RangeMinimumQuery(const vector<int>& A) : nextIndex(A.size(), vector<int>(10, -1)) {
		for (int i = A.size() - 1; i >= 0; --i) {
			if (i < A.size() - 1)
				nextIndex[i] = nextIndex[i + 1];
			nextIndex[i][A[i]] = i;
		}
	}
	int min(int L, int R) const {
		for (int digit = 9; digit >= 0; --digit) {
			const int i = nextIndex[L][digit];
			if (i != -1 && i <= R)
				return i;
		}
		return -1;
	}
};

class Solution {
private:
	static void addState(unordered_map<int, int>& states, int i, int j) {
		/*
		 * If we have two states: (i, a) and (i, b), where a < b,
		 * because starting from (i, a) can get no worse than starting from (i, b),
		 * we only need to store (i, a) into states.
		 *
		 * Therefore, the size of states is only O(m).
		 */
		if (!states.count(i) || states[i] > j)
			states[i] = j;
	}
public:
	/* time: O(m + n + k * min(m, n)), space: O(m + n) auxiliary (i.e. does not count output itself) */
	static vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
		if (nums1.size() > nums2.size())
			return maxNumber(nums2, nums1, k);

		const int m = nums1.size(), n = nums2.size();
		const RangeMinimumQuery LUT1(nums1), LUT2(nums2);

		unordered_map<int, int> currStates;
		addState(currStates, 0, 0);

		vector<int> ans(k);
		for (int d = 0; d < k; ++d) {
			int nextDigit = -1;
			unordered_map<int, int> nextStates;

			for (const auto& it : currStates) {
				const int i = it.first, j = it.second;
				const int maxSkippable = (m - i) + (n - j) - (k - d);
				const int iMax = min(i + maxSkippable, m - 1);
				const int jMax = min(j + maxSkippable, n - 1);

				if (i <= iMax) {
					const int sel = LUT1.min(i, iMax);
					if (nums1[sel] > nextDigit)
						nextDigit = nums1[sel], nextStates.clear();
					if (nums1[sel] == nextDigit)
						addState(nextStates, sel + 1, j);
				}

				if (j <= jMax) {
					const int sel = LUT2.min(j, jMax);
					if (nums2[sel] > nextDigit)
						nextDigit = nums2[sel], nextStates.clear();
					if (nums2[sel] == nextDigit)
						addState(nextStates, i, sel + 1);
				}
			}
			ans[d] = nextDigit, currStates = move(nextStates);
		}
		return ans;
	}
};
