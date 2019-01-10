class LRUCache {
private:
	typedef pair<int, int> P;
	typedef list<P> L;
	typedef L::iterator I;
	typedef unordered_map<int, I> H;
	L entryList;
	H keyToIter;
	int maxSize;
public:
	/* time: O(1), space: O(1) auxiliary (i.e. does not count cache capacity itself) */
	LRUCache(int capacity) : maxSize(capacity) { }

	/* time: O(1), space: O(1) auxiliary (i.e. does not count cache capacity itself) */
	int get(int key) {
		if (!keyToIter.count(key))
			return -1;
		entryList.splice(entryList.begin(), entryList, keyToIter[key]);
		return keyToIter[key]->second;
	}

	/* time: O(1), space: O(1) auxiliary (i.e. does not count cache capacity itself) */
	void put(int key, int value) {
		if (get(key) != -1) {
			keyToIter[key]->second = value;
			return;
		}

		if (entryList.size() == maxSize) {
			const int LRUKey = entryList.back().first;
			keyToIter.erase(LRUKey);
			entryList.pop_back();
		}

		entryList.emplace_front(key, value);
		keyToIter[key] = entryList.begin();
	}
};
