class Solution {
 public:
  /*
   * time: O(n + L), where n = S.size(), L = total # of chars in words
   * space: O(m), where m = words.size()
   */
  int numMatchingSubseq(const string& S, const vector<string>& words) {
    const int n = S.size(), m = words.size();
    vector<int> matched_len(m);
    vector<int> bucket[26];
    for (int i = 0; i < m; ++i) bucket[words[i][0] - 'a'].push_back(i);

    int ans = 0;
    for (char c : S) {
      const auto matched = move(bucket[c - 'a']);
      for (int i : matched) {
        if (++matched_len[i] < words[i].size())
          bucket[words[i][matched_len[i]] - 'a'].push_back(i);
        else
          ++ans;
      }
    }
    return ans;
  }
};
