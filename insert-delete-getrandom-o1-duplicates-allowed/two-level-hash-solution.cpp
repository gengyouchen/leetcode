class RandomizedCollection {
private:
	unordered_map<int, unordered_set<int>> num2indices;
	vector<int> nums;
public:
	/* time: O(1), space: O(1) */
	RandomizedCollection() { srand(time(NULL)); }

	/* time: O(1), space: O(1) auxiliary (i.e. does not count array and hash table itself) */
	bool insert(int val) {
		nums.push_back(val), num2indices[val].insert(nums.size() - 1);
		return num2indices[val].size() == 1;
	}

	/* time: O(1), space: O(1) auxiliary (i.e. does not count array and hash table itself) */
	bool remove(int val) {
		const auto it = num2indices.find(val);
		if (it == num2indices.end())
			return false;
		auto& indices = it->second;

		const int lastVal = nums.back();
		if (lastVal != val) {
			const int victim = *indices.begin();
			indices.erase(victim), nums[victim] = lastVal, num2indices[lastVal].insert(victim);
		}
		num2indices[lastVal].erase(nums.size() - 1), nums.pop_back();

		if (indices.empty())
			num2indices.erase(it);
		return true;
	}

	/* time: O(1), space: O(1) */
	int getRandom() const {
		if (nums.empty())
			return -1;
		return nums[rand() % nums.size()];
	}
};
