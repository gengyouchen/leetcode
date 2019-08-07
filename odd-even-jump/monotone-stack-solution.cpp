class Solution {
private:
	/* See LeetCode 496 - Next Greater Element I */
	static vector<int> nextGreaterElements(const vector<int>& indices) {
		const int n = indices.size();
		vector<int> h(n);
		stack<int> mono;
		for (int i : indices) {
			while (!mono.empty() && i > mono.top())
				h[mono.top()] = i, mono.pop();
			mono.push(i);
		}
		return h;
	}
public:
	/* time: O(n*log(n)), space: O(n) */
	static int oddEvenJumps(const vector<int>& A) {
		const int n = A.size();
		vector<int> indices(n);
		iota(indices.begin(), indices.end(), 0);

		auto byVal = [&](int i, int j) { return (A[i] != A[j]) ? (A[i] < A[j]) : (i < j); };
		sort(indices.begin(), indices.end(), byVal);
		const auto adjOdd = nextGreaterElements(indices);

		auto byValDesc = [&](int i, int j) { return (A[i] != A[j]) ? (A[i] > A[j]) : (i < j); };
		sort(indices.begin(), indices.end(), byValDesc);
		const auto adjEven = nextGreaterElements(indices);

		vector<bool> goodOdd(n), goodEven(n);
		for (int i = n - 1; i >= 0; --i) {
			if (i == n - 1) {
				goodOdd[i] = goodEven[i] = true;
			} else {
				if (adjOdd[i])
					goodOdd[i] = goodEven[adjOdd[i]];
				if (adjEven[i])
					goodEven[i] = goodOdd[adjEven[i]];
			}
		}
		return count(goodOdd.begin(), goodOdd.end(), true);
	}
};
