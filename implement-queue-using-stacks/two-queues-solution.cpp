class MyQueue {
private:
	stack<int> in, out;
public:
	/* time: O(1), space: O(1) auxiliary (i.e. does not count stack capacity itself) */
	MyQueue() { }

	/* time: O(1), space: O(1) auxiliary (i.e. does not count stack capacity itself) */
	void push(int x) {
		if (out.empty())
			out.push(x);
		else
			in.push(x);
	}

	/* time: O(1) amortized, space: O(1) auxiliary (i.e. does not count stack capacity itself) */
	int pop() {
		const int x = out.top();
		out.pop();
		if (out.empty()) {
			while (!in.empty())
				out.push(in.top()), in.pop();
		}
		return x;
	}

	/* time: O(1), space: O(1) auxiliary (i.e. does not count stack capacity itself) */
	int peek() const { return out.top(); }

	/* time: O(1), space: O(1) auxiliary (i.e. does not count stack capacity itself) */
	bool empty() const { return out.empty(); }
};
