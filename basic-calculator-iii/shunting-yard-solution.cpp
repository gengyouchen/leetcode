class Solution {
private:
	enum OP { ADD, SUB, MUL, DIV, OPEN, CLOSE };
	const int precedence[6] = { 1, 1, 2, 2, INT_MAX, INT_MIN };
public:
	/* time: O(n), space: O(n) */
	int calculate(const string& s) {
		stack<long> out;
		stack<int> ops;

		auto ops_push = [&](int op) {
			if (op != OPEN) {
				while (!ops.empty() && (ops.top() != OPEN) && (op == CLOSE || precedence[op] <= precedence[ops.top()])) {
					const long num = out.top();
					out.pop();

					switch (ops.top()) {
					case ADD:
						out.top() += num;
						break;
					case SUB:
						out.top() -= num;
						break;
					case MUL:
						out.top() *= num;
						break;
					case DIV:
						out.top() /= num;
						break;
					}
					ops.pop();
				}
			}

			if (op == CLOSE)
				ops.pop();
			else
				ops.push(op);
		};

		ops_push(OPEN);

		bool inNum = false;
		long num = 0;
		for (char c : s) {
			if (c != ' ') {
				if (isdigit(c)) {
					num = num * 10 + (c - '0'), inNum = true;
				} else {
					if (inNum)
						out.push(num), num = 0, inNum = false;
					switch (c) {
					case '+':
						ops_push(ADD);
						break;
					case '-':
						ops_push(SUB);
						break;
					case '*':
						ops_push(MUL);
						break;
					case '/':
						ops_push(DIV);
						break;
					case '(':
						ops_push(OPEN);
						break;
					case ')':
						ops_push(CLOSE);
						break;
					}
				}
			}
		}
		if (inNum)
			out.push(num), num = 0, inNum = false;

		ops_push(CLOSE);
		return out.top();
	}
};
