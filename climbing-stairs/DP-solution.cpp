class Solution {
public:
	/*
	 * time: O(n), space: O(1)
	 *
	 * The recursive definition of climbStairs is:
	 * climbStairs(0) = 1
	 * climbStairs(1) = 1
	 * climbStairs(n) = climbStairs(n-1) + climbStairs(n-2)
	 *
	 * This is exactly the same recursive definition of the Fibonacci number
	 * We can use DP to calculate Fibonacci(n) in O(n) time, O(1) space
	 *
	 * The Fibonacci number is also defined as a closed-form matrix expression:
	 *         |1 1|             | Fibonacci(n+1) Fibonacci(n)   |
	 * Let A = |1 0|, then A^n = | Fibonacci(n)   Fibonacci(n-1) |
	 *
	 * By using the "Repeated Squaring" method (See the CLRS textbook 31.6),
	 * we can calculate Fibonacci(n) in O(log(n)) time, O(1) space
	 */
	int climbStairs(int n) {
		int _Fibonacci[2];
		auto Fibonacci = [&](int i) -> int& { return _Fibonacci[i % 2]; };

		for (int i = 0; i <= n; ++i)
			if (i <= 1)
				Fibonacci(i) = 1;
			else
				Fibonacci(i) = Fibonacci(i - 1) + Fibonacci(i - 2);
		return Fibonacci(n);
	}
};
