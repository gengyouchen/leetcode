class Solution {
public:
	/*
	 * time: O(n*log(n)), space: O(1) auxiliary (i.e. does not count input & output itself),
	 * assuming that all integers are 32-bit, so to_string() takes O(1) time and O(1) space
	 */
	string largestNumber(vector<int>& nums) {
		if (nums.empty())
			return "0";
		auto comp = [](int a, int b) {
			const auto x = to_string(a), y = to_string(b);
			return (x + y) > (y + x);
		};
		make_heap(nums.begin(), nums.end(), comp);
		sort_heap(nums.begin(), nums.end(), comp);
		if (!nums.front())
			return "0";
		string ans;
		for (int num : nums)
			ans += to_string(num);
		return ans;
	}
};
