class Solution {
private:
	enum OP { ADD, SUB, MUL, DIV };
	const int precedence[4] = { 1, 1, 2, 2 };
public:
	/* time: O(n), space: O(n) */
	int calculate(const string& s) {
		stack<long> out;
		stack<int> ops;

		auto ops_push = [&](int op) {
			while (!ops.empty() && precedence[op] <= precedence[ops.top()]) {
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

			ops.push(op);
		};

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
					}
				}
			}
		}
		if (inNum)
			out.push(num), num = 0, inNum = false;

		ops_push(ADD);
		return out.top();
	}
};
