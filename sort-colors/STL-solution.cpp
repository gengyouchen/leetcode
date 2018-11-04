class Solution {
private:
	enum Color { RED = 0, WHITE = 1, BLUE = 2 };
public:
	/*
	 * time: O(n), space: O(1) auxiliary (i.e. does not count input & output itself)
	 * This is exactly the Dutch National Flag (DNF) problem by Edsger Dijkstra
	 */
	void sortColors(vector<int>& nums) {
		auto lastRed = partition(nums.begin(), nums.end(), [](int c) { return c == RED; });
		partition(lastRed, nums.end(), [](int c) { return c == WHITE; });
	}
};
