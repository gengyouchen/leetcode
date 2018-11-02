class Solution {
private:
	struct Matrix {
		array<array<int, 2>, 2> val;
		Matrix operator*(const Matrix& rhs) const {
			Matrix ans;
			for (int row = 0; row < 2; ++row)
				for (int col = 0; col < 2; ++col) {
					ans.val[row][col] = 0;
					for (int i = 0; i < 2; ++i)
						ans.val[row][col] += val[row][i] * rhs.val[i][col];
				}
			return ans;
		}
	};
public:
	/*
	 * time: O(log(n)), space: O(1)
	 *
	 * The recursive definition of climbStairs is:
	 * climbStairs(0) = 1
	 * climbStairs(1) = 1
	 * climbStairs(n + 1) = climbStairs(n) + climbStairs(n - 1)
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
		Matrix base;
		base.val[0][0] = 1, base.val[0][1] = 1, base.val[1][0] = 1, base.val[1][1] = 0;

		Matrix ans = base;
		for (unsigned bit = 1; bit; bit <<= 1) {
			if (n & bit)
				ans = ans * base;
			base = base * base;
		}
		return ans.val[0][1];
	}
};
