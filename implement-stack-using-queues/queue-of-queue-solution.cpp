class MyStack {
private:
	typedef queue<void*> Queue;
	Queue *q = NULL;
public:
	/* time: O(1), space: O(1) auxiliary (i.e. does not count queue capacity itself) */
	MyStack() { }

	/* time: O(1), space: O(1) auxiliary (i.e. does not count queue capacity itself) */
	void push(int x) {
		const auto container = new Queue();
		container->push(new int(x)), container->push(q), q = container;
	}

	/* time: O(1), space: O(1) auxiliary (i.e. does not count queue capacity itself) */
	int pop() {
		const auto container = q;
		const auto *val = (int *)container->front();
		container->pop(), q = (Queue *)container->front(), container->pop();
		delete container;

		const int x = *val;
		delete val;
		return x;
	}

	/* time: O(1), space: O(1) auxiliary (i.e. does not count queue capacity itself) */
	int top() const { return *(int *)q->front(); }

	/* time: O(1), space: O(1) auxiliary (i.e. does not count queue capacity itself) */
	bool empty() const { return !q; }
};
