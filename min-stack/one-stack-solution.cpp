class MinStack {
private:
	stack<int> s;
	int lastCandidate = INT_MAX;
public:
	/* time: O(1), space: O(1) auxiliary (i.e. does not count stack capacity itself) */
	MinStack() { }

	/* time: O(1), space: O(1) auxiliary (i.e. does not count stack capacity itself) */
	void push(int x) {
		if (x <= lastCandidate)
			s.push(lastCandidate), lastCandidate = x;
		s.push(x);
	}

	/* time: O(1), space: O(1) auxiliary (i.e. does not count stack capacity itself) */
	void pop() {
		const int x = s.top();
		s.pop();
		if (x == lastCandidate)
			lastCandidate = s.top(), s.pop();
	}

	/* time: O(1), space: O(1) auxiliary (i.e. does not count stack capacity itself) */
	int top() const { return s.top(); }

	/* time: O(1), space: O(1) auxiliary (i.e. does not count stack capacity itself) */
	int getMin() const { return lastCandidate; }
};
