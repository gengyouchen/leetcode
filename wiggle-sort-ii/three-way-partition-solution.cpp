class Solution {
private:
	enum Color { RED = 0, WHITE = 1, BLUE = 2 };
public:
	/* time: O(n), space: O(1) auxiliary (i.e. does not count input & output itself) */
	void wiggleSort(vector<int>& nums) {
		const int n = nums.size();
		const auto mid = nums.begin() + n / 2;
		nth_element(nums.begin(), mid, nums.end());
		const int median = *mid;

		auto A = [&](int i) -> int& { return nums[(i * 2 + 1) % (n | 1)]; };
		auto color = [&](int i) { return (A(i) > median) ? RED : (A(i) == median) ? WHITE : BLUE; };
		/*
		 * This is exactly the Dutch National Flag (DNF) problem by Edsger Dijkstra
		 * See LeetCode 75 - Sort Colors
		 */
		int iLastRed = 0, i = iLastRed, iFirstBlue = n;
		while (i != iFirstBlue) {
			if (color(i) == RED)
				swap(A(i++), A(iLastRed++));
			else if (color(i) == BLUE)
				swap(A(i), A(--iFirstBlue));
			else
				++i;
		}
	}
};
