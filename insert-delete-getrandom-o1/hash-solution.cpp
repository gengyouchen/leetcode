class RandomizedSet {
private:
	unordered_map<int, int> num2index;
	vector<int> nums;
	void swapAt(int i, int j) {
		if (i != j)
			num2index[nums[i]] = j, num2index[nums[j]] = i, swap(nums[i], nums[j]);
	}
public:
	/* time: O(1), space: O(1) */
	RandomizedSet() { srand(time(NULL)); }

	/* time: O(1), space: O(1) auxiliary (i.e. does not count array and hash table itself) */
	bool insert(int val) {
		if (num2index.count(val))
			return false;
		nums.push_back(val), num2index[val] = nums.size() - 1;
		return true;
	}

	/* time: O(1), space: O(1) auxiliary (i.e. does not count array and hash table itself) */
	bool remove(int val) {
		const auto it = num2index.find(val);
		if (it == num2index.end())
			return false;

		const int victim = it->second;
		swapAt(victim, nums.size() - 1), nums.pop_back(), num2index.erase(it);
		return true;
	}

	/* time: O(1), space: O(1) */
	int getRandom() const {
		if (nums.empty())
			return -1;
		return nums[rand() % nums.size()];
	}
};
