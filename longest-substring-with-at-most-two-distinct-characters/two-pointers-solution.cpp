class Solution {
public:
	/* time: O(n), space: O(1) */
	int lengthOfLongestSubstringTwoDistinct(const string& s) {
		/*
		 * Notice that we can solve this problem without using hash table
		 *
		 * For hash table solution,
		 * see LeetCode 340 - Longest Substring with At Most K Distinct Characters
		 * where k = 2 for this problem
		 */
		char key[2] = {};
		int val[2] = {};
		auto findSlot = [&](char c) { return (key[0] == c && val[0]) ? 0 : (key[1] == c && val[1]) ? 1 : -1; };
		auto findEmpty = [&]() { return (!val[0]) ? 0 : (!val[1]) ? 1 : -1; };
		auto decrease = [&](char c) { --val[findSlot(c)]; };
		auto increase = [&](char c) {
			const int slot = (findSlot(c) == -1) ? findEmpty() : findSlot(c);
			key[slot] = c, ++val[slot];
		};

		int ans = 0;
		auto L = s.begin();
		for (auto R = s.begin(); R != s.end(); ++R) {
			while (findEmpty() == -1 && findSlot(*R) == -1)
				decrease(*L++);
			increase(*R);
			ans = max(ans, (int)distance(L, R + 1));
		}
		return ans;
	}
};
