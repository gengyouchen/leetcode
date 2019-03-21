class LFUCache {
private:
	typedef pair<int, int> P;
	typedef list<P> L;
	typedef L::iterator I;
	typedef unordered_map<int, L> C2L;
	typedef unordered_map<int, I> K2I;
	typedef unordered_map<int, int> K2C;
	C2L countToEntryList;
	K2I keyToIter;
	K2C keyToCount;
	int maxSize, minCount;
public:
	/* time: O(1), space: O(1) auxiliary (i.e. does not count cache capacity itself) */
	LFUCache(int capacity) : maxSize(capacity) { }

	/* time: O(1), space: O(1) auxiliary (i.e. does not count cache capacity itself) */
	int get(int key) {
		if (!keyToIter.count(key))
			return -1;

		const int oldCount = keyToCount[key], newCount = oldCount + 1;
		auto& oldEntryList = countToEntryList[oldCount];
		auto& newEntryList = countToEntryList[newCount];

		newEntryList.splice(newEntryList.begin(), oldEntryList, keyToIter[key]);
		keyToIter[key] = newEntryList.begin(), keyToCount[key] = newCount;

		if (oldEntryList.empty()) {
			countToEntryList.erase(oldCount);
			if (minCount == oldCount)
				minCount = newCount;
		}
		return keyToIter[key]->second;
	}

	/* time: O(1), space: O(1) auxiliary (i.e. does not count cache capacity itself) */
	void put(int key, int value) {
		if (!maxSize)
			return;

		if (get(key) != -1) {
			keyToIter[key]->second = value;
			return;
		}

		if (keyToIter.size() == maxSize) {
			auto& entryList = countToEntryList[minCount];
			const int LRFKey = entryList.back().first;
			keyToIter.erase(LRFKey), keyToCount.erase(LRFKey);
			entryList.pop_back();
			if (entryList.empty())
				countToEntryList.erase(minCount);
		}

		minCount = 1;
		auto& entryList = countToEntryList[minCount];
		entryList.emplace_front(key, value);
		keyToIter[key] = entryList.begin(), keyToCount[key] = minCount;
	}
};
