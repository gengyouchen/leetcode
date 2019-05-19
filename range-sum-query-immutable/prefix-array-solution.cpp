class NumArray {
private:
	vector<int> prefix;
public:
	/* time: O(n), space: O(1) auxiliary (i.e. does not count prefix array itself) */
	NumArray(const vector<int>& nums) : prefix(nums.size() + 1) {
		partial_sum(nums.begin(), nums.end(), prefix.begin() + 1);
	}
	/* time: O(1), space: O(1) auxiliary (i.e. does not count prefix array itself) */
	int sumRange(int i, int j) const { return prefix[j + 1] - prefix[i]; }
};
