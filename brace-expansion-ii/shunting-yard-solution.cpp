class Operand {
private:
	unordered_set<string> words;
public:
	Operand(char c) {
		words.emplace(1, c);
	}
	void Union(const Operand& rhs) {
		words.insert(rhs.words.begin(), rhs.words.end());
	}
	void Cross(const Operand& rhs) {
		unordered_set<string> output;
		for (const auto& X : words) {
			for (const auto& Y : rhs.words)
				output.insert(X + Y);
		}
		words = move(output);
	}
	vector<string> Print() const {
		vector<string> ret(words.begin(), words.end());
		sort(ret.begin(), ret.end());
		return ret;
	}
};

class Solution {
public:
	/* time: O(n), space: O(n), if we treat the largest operand's size as O(1) space */
	static vector<string> braceExpansionII(const string& expression) {
		const int n = expression.size();

		enum OP { UNION, CROSS, OPEN, CLOSE };
		const int precedence[4] = { 1, 2, INT_MAX, INT_MAX };

		stack<Operand> out;
		stack<int> ops;
		auto ops_push = [&](int op) {
			if (op == OPEN) {
				ops.push(op);
				return;
			}

			while (!ops.empty()) {
				if (ops.top() == OPEN)
					break;
				if (op != CLOSE && precedence[op] > precedence[ops.top()])
					break;

				const auto rhs = move(out.top());
				out.pop();

				switch (ops.top()) {
				case UNION:
					out.top().Union(rhs);
					break;
				case CROSS:
					out.top().Cross(rhs);
					break;
				}
				ops.pop();
			}

			if (op == CLOSE)
				ops.pop();
			else
				ops.push(op);
		};

		ops_push(OPEN);
		for (int i = 0; i < n; ++i) {
			const char c = expression[i];
			if (i > 0 && (isalpha(c) || c == '{')) {
				const char prev = expression[i - 1];
				if (isalpha(prev) || prev == '}')
					ops_push(CROSS);
			}

			switch (c) {
			case '{':
				ops_push(OPEN);
				break;
			case '}':
				ops_push(CLOSE);
				break;
			case ',':
				ops_push(UNION);
				break;
			default:
				out.emplace(c);
			}
		}
		ops_push(CLOSE);
		return out.top().Print();
	}
};
