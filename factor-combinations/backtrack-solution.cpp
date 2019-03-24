class Solution {
private:
	typedef vector<int>::const_iterator I;
	typedef function<void(I, I, int)> F;
public:
	/*
	 * time: O(m * b^m), space: O(b) auxiliary (i.e. does not count output itself),
	 * where b = # of divisor for input n, m = log(b)
	 */
	vector<vector<int>> getFactors(int n) {
		vector<int> factor;
		const int low = 2, high = sqrt(n);
		for (int i = low; i <= high; ++i) {
			if (n % i == 0)
				factor.push_back(i);
		}
		vector<vector<int>> ans;
		vector<int> buf;
		F backtrack = [&](auto first, auto last, int quotient) {
			for (auto it = first; (it != last) && (quotient >= *it); ++it) {
				if (quotient % *it == 0) {
					buf.push_back(*it);
					backtrack(it, last, quotient / *it);
					buf.pop_back();
				}
			}
			if (!buf.empty() && quotient >= buf.back()) {
				buf.push_back(quotient);
				ans.push_back(buf);
				buf.pop_back();
			}
		};
		backtrack(factor.begin(), factor.end(), n);
		return ans;
	}
};
