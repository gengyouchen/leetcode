class TwoSum {
private:
	unordered_map<int, int> nAppeared;
	int nTotal = 0;
	long maxNum[2] = { LONG_MIN, LONG_MIN };
	long minNum[2] = { LONG_MAX, LONG_MAX };
public:
	/* time: O(1), space: O(1) */
	TwoSum() { }

	/* time: O(1), space: O(1) auxiliary (i.e. does not count hash table itself) */
	void add(int number) {
		++nAppeared[number], ++nTotal;

		if (number > maxNum[0])
			maxNum[1] = maxNum[0], maxNum[0] = number;
		else if (number > maxNum[1])
			maxNum[1] = number;

		if (number < minNum[0])
			minNum[1] = minNum[0], minNum[0] = number;
		else if (number < minNum[1])
			minNum[1] = number;
	}

	/* time: O(n), space: O(1) auxiliary (i.e. does not count hash table itself) */
	bool find(int value) {
		if (nTotal >= 2) {
			if (maxNum[0] + maxNum[1] < value)
				return false;
			if (minNum[0] + minNum[1] > value)
				return false;
		}

		for (auto it : nAppeared) {
			auto complement = nAppeared.find(value - it.first);
			if (complement != nAppeared.end()) {
				if (complement->first != it.first)
					return true;
				else if (complement->second >= 2)
					return true;
			}
		}
		return false;
	}
};
