class Solution {
 public:
  /* time: O(n), space: O(1), where n = str1.size() = str2.size() */
  bool canConvert(const string& str1, const string& str2) {
    /* Convert n mappings into at most 26 linked lists */
    int n = str1.size();
    int next[26];
    bool is_head[26];
    fill(next, next + 26, -1);
    fill(is_head, is_head + 26, true);

    for (int i = 0; i < n; ++i) {
      int x = str1[i] - 'a', y = str2[i] - 'a';
      if (next[x] == -1) {
        next[x] = y;
        is_head[y] = false;
      }
      if (next[x] != y) return false;
    }

    for (int x = 0; x < 26; ++x) {
      /*
       * A linked lists having a head can be processed without an additional
       *   helper letter, and will produce a helper letter after solved.
       *
       *   Case 1: a -> b -> c -> d -> -1 (has a tail)
       *     1. Replace 'c' with 'd'
       *     2. Replace 'b' with 'c'
       *     3. Replace 'a' with 'b'
       *     Now we can use 'a' as a helper letter to solve other linked lists
       *
       *   Case 2: a -> b -> c -> d -> e -> f -> g -> d (has a loop)
       *     1. Replace 'c' with 'g'
       *     2. Replace 'b' with 'c'
       *     3. Replace 'a' with 'b'
       *     Now we can use 'a' as a helper letter to break that loop
       *
       *     1. Replace 'd' with 'a'
       *     2. Replace 'g' with 'd'
       *     3. Replace 'f' with 'g'
       *     4. Replace 'e' with 'f'
       *     5. Replace 'a' with 'e'
       *     Now we can use 'a' as a helper letter to solve other linked lists
       */
      if (is_head[x]) return true;
    }

    /*
     * If every linked list doesn't have a head (e.g. a -> b -> c -> a),
     *   we won't have any additional helper letter to solve anyone.
     *
     * However, if str1 == str2, which means every linked list has length == 1
     *   (e.g. a -> a), then we don't need to solve them.
     */
    return str1 == str2;
  }
};
