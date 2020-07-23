class Solution {
 public:
  /*
   * time: O(n), space: O(1)
   *
   * See also:
   *   136. Single Number
   */
  Node* findRoot(const vector<Node*> tree) {
    int ans = 0;
    for (auto x : tree) {
      ans ^= x->val;
      for (auto child : x->children) ans ^= child->val;
    }
    for (auto x : tree)
      if (x->val == ans) return x;
    return nullptr;
  }
};
