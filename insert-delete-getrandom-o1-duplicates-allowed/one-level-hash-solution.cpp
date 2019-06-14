class RandomizedCollection {
private:
	unordered_map<int, vector<int>> num2indices;
	vector<pair<int, int>> nums;
	void swapAt(int i, int j) {
		swap(nums[i], nums[j]);
		swap(num2indices[nums[i].first][nums[i].second], num2indices[nums[j].first][nums[j].second]);
	}
public:
	/* time: O(1), space: O(1) */
	RandomizedCollection() { srand(time(NULL)); }

	/* time: O(1), space: O(1) auxiliary (i.e. does not count array and hash table itself) */
	bool insert(int val) {
		auto& indices = num2indices[val];
		indices.push_back(nums.size()), nums.emplace_back(val, indices.size() - 1);
		return indices.size() == 1;
	}

	/* time: O(1), space: O(1) auxiliary (i.e. does not count array and hash table itself) */
	bool remove(int val) {
		const auto it = num2indices.find(val);
		if (it == num2indices.end())
			return false;
		auto& indices = it->second;

		swapAt(indices.back(), nums.size() - 1), indices.pop_back(), nums.pop_back();
		if (indices.empty())
			num2indices.erase(it);
		return true;
	}

	/* time: O(1), space: O(1) */
	int getRandom() const {
		if (nums.empty())
			return -1;
		return nums[rand() % nums.size()].first;
	}
};
