class Solution {
public:
	/* time: O(n), space: O(n) */
	int evalRPN(const vector<string>& tokens) {
		stack<int> s;
		int a, b;
		for (const string& token : tokens)
			if (token == "+")
				b = s.top(), s.pop(), a = s.top(), s.pop(), s.push(a + b);
			else if (token == "-")
				b = s.top(), s.pop(), a = s.top(), s.pop(), s.push(a - b);
			else if (token == "*")
				b = s.top(), s.pop(), a = s.top(), s.pop(), s.push(a * b);
			else if (token == "/")
				b = s.top(), s.pop(), a = s.top(), s.pop(), s.push(a / b);
			else
				s.push(stoi(token));
		return s.top();
	}
};
