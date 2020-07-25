class Solution {
 public:
  /* time: O(n), space: O(n), where n = # of nodes */
  Node* moveSubTree(Node* root, Node* p, Node* q) {
    Node *p_parent, *q_parent;
    int p_parent_index, q_parent_index;
    bool is_q_under_p = false;

    auto dfs = [&](const auto& dfs, Node* x, Node* parent, int parent_index,
                   bool is_under_p) -> void {
      if (x == p) {
        p_parent = parent;
        p_parent_index = parent_index;
        is_under_p = true;
      }

      if (x == q) {
        q_parent = parent;
        q_parent_index = parent_index;
        if (is_under_p) is_q_under_p = true;
      }

      int n = x->children.size();
      for (int i = 0; i < n; ++i) dfs(dfs, x->children[i], x, i, is_under_p);
    };
    dfs(dfs, root, nullptr, -1, false);

    if (p_parent == q) return root;
    if (is_q_under_p) {
      remove(q_parent, q_parent_index);
      if (p_parent)
        replace(p_parent, p_parent_index, q);
      else
        root = q;
    } else {
      remove(p_parent, p_parent_index);
    }
    add(q, p);
    return root;
  }

 private:
  void add(Node* parent, Node* x) { parent->children.push_back(x); }
  void remove(Node* parent, int parent_index) {
    parent->children.erase(parent->children.begin() + parent_index);
  }
  void replace(Node* parent, int parent_index, Node* x) {
    parent->children[parent_index] = x;
  }
};
