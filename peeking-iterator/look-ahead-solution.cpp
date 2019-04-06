// Below is the interface for Iterator, which is already defined for you.
// **DO NOT** modify the interface for Iterator.
class Iterator {
	struct Data;
	Data* data;
public:
	Iterator(const vector<int>& nums);
	Iterator(const Iterator& iter);
	virtual ~Iterator();
	// Returns the next element in the iteration.
	int next();
	// Returns true if the iteration has more elements.
	bool hasNext() const;
};

class PeekingIterator : public Iterator {
private:
	int nextValue;
	bool hasNextValue;
public:
	/* time: O(1), space: O(1) */
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
		hasNextValue = Iterator::hasNext();
		if (hasNextValue)
			nextValue = Iterator::next();
	}

	/* time: O(1), space: O(1) */
	int peek() const { return nextValue; }

	/* time: O(1), space: O(1) */
	int next() {
		const int value = nextValue;
		hasNextValue = Iterator::hasNext();
		if (hasNextValue)
			nextValue = Iterator::next();
		return value;
	}

	/* time: O(1), space: O(1) */
	bool hasNext() const { return hasNextValue; }
};
