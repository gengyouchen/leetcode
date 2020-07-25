class Solution {
 public:
  /* time: O(1), space: O(1) */
  int numWaterBottles(int numBottles, int numExchange) {
    int ans = numBottles;
    /*
     * We can exchange k empty bottles for 1 full bottle
     * <-> We can exchange k empty bottles for 1 empty bottle + 1 water unit
     * <-> As long as our # of empty bottles >= k,
     *     we can exchange (k - 1) empty bottles for 1 water unit
     */
    ans += (numBottles - 1) / (numExchange - 1);
    return ans;
  }
};
