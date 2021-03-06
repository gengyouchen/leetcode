class MyStack {
private:
	queue<int> q;
public:
	/* time: O(1), space: O(1) auxiliary (i.e. does not count queue capacity itself) */
	MyStack() { }

	/*
	 * time: O(n), space: O(1) auxiliary (i.e. does not count queue capacity itself),
	 * where n = # of elements in queue
	 */
	void push(int x) {
		q.push(x);
		for (int i = q.size() - 1; i > 0; --i)
			q.push(q.front()), q.pop();
	}

	/* time: O(1), space: O(1) auxiliary (i.e. does not count queue capacity itself) */
	int pop() {
		int x = q.front();
		q.pop();
		return x;
	}

	/* time: O(1), space: O(1) auxiliary (i.e. does not count queue capacity itself) */
	int top() const { return q.front(); }

	/* time: O(1), space: O(1) auxiliary (i.e. does not count queue capacity itself) */
	bool empty() const { return q.empty(); }
};
