class Solution {
 public:
  /*
   * time: O(n), space: O(1), where n = arr.size()
   *
   * See also:
   *   209. Minimum Size Subarray Sum
   *   862. Shortest Subarray with Sum at Least K
   */
  int closestToTarget(const vector<int>& arr, int target) {
    /*
     * Because for any subarrays X and Y, if X is inside Y, AND(X) >= AND(Y),
     *   we can use a sliding window to generate the shortest subarray [L...R]
     *   for each L such that AND([L...R]) < target.
     */
    int n = arr.size(), L = 0, ans = INT_MAX;
    Window subarray;
    for (int R = 0; R < n; ++R) {
      subarray.insert(arr[R]);
      ans = min(ans, abs(subarray.AND() - target));

      while (!subarray.empty() && subarray.AND() < target) {
        subarray.erase(arr[L++]);
        if (!subarray.empty()) ans = min(ans, abs(subarray.AND() - target));
      }
    }
    return ans;
  }

 private:
  class Window {
   public:
    bool empty() { return count == 0; }

    void insert(int num) {
      for (int i = 0; i < 32; ++i) {
        int mask = 1 << i;
        if (num & mask) ++bit1_count[i];
      }
      ++count;
    }

    void erase(int num) {
      for (int i = 0; i < 32; ++i) {
        int mask = 1 << i;
        if (num & mask) --bit1_count[i];
      }
      --count;
    }

    int AND() {
      int ret = 0;
      for (int i = 0; i < 32; ++i) {
        int mask = 1 << i;
        if (bit1_count[i] == count) ret |= mask;
      }
      return ret;
    }

   private:
    int count = 0;
    int bit1_count[32] = {};
  };
};
