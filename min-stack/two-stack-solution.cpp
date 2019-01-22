class MinStack {
private:
	stack<int> all, candidate;
public:
	/* time: O(1), space: O(1) auxiliary (i.e. does not count stack capacity itself) */
	MinStack() { }

	/* time: O(1), space: O(1) auxiliary (i.e. does not count stack capacity itself) */
	void push(int x) {
		all.push(x);
		if (candidate.empty() || x <= candidate.top())
			candidate.push(x);
	}

	/* time: O(1), space: O(1) auxiliary (i.e. does not count stack capacity itself) */
	void pop() {
		if (candidate.top() == all.top())
			candidate.pop();
		all.pop();
	}

	/* time: O(1), space: O(1) auxiliary (i.e. does not count stack capacity itself) */
	int top() const { return all.top(); }

	/* time: O(1), space: O(1) auxiliary (i.e. does not count stack capacity itself) */
	int getMin() const { return candidate.top(); }
};
