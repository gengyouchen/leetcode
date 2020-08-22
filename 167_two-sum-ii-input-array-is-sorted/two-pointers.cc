class Solution {
 public:
  /* time: O(n), space: O(1) */
  vector<int> twoSum(const vector<int>& numbers, int target) {
    const int n = numbers.size();
    int L = 0, R = n - 1;
    while (L < R) {
      const int sum = numbers[L] + numbers[R];
      if (sum < target) {
        /*
         * For any i between L+1 ~ R, numbers[L] + numbers[i] < target,
         * so L can be excluded.
         */
        ++L;
      } else if (sum > target) {
        /*
         * For any i between L ~ R-1, numbers[i] + numbers[R] > target,
         * so R can be excluded.
         */
        --R;
      } else {
        return {L + 1, R + 1}; /* found */
      }
    }
    return {0, 0}; /* not found */
  }
};
