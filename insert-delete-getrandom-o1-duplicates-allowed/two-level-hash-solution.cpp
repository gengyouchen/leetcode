class RandomizedCollection {
private:
	unordered_map<int, unordered_set<int>> num2indices;
	vector<int> nums;
	void swapAt(int i, int j) {
		if (nums[i] != nums[j]) {
			num2indices[nums[i]].erase(i), num2indices[nums[i]].insert(j);
			num2indices[nums[j]].erase(j), num2indices[nums[j]].insert(i);
			swap(nums[i], nums[j]);
		}
	}
public:
	/* time: O(1), space: O(1) */
	RandomizedCollection() { srand(time(NULL)); }

	/* time: O(1), space: O(1) auxiliary (i.e. does not count array and hash table itself) */
	bool insert(int val) {
		auto& indices = num2indices[val];
		nums.push_back(val), indices.insert(nums.size() - 1);
		return indices.size() == 1;
	}

	/* time: O(1), space: O(1) auxiliary (i.e. does not count array and hash table itself) */
	bool remove(int val) {
		const auto it = num2indices.find(val);
		if (it == num2indices.end())
			return false;
		auto& indices = it->second;

		const int victim = *indices.begin();
		swapAt(victim, nums.size() - 1), indices.erase(nums.size() - 1), nums.pop_back();
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
