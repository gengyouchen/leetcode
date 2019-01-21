class Solution {
private:
	template <class I, class T, class F>
	void sortedTwoSum(I first, I last, T target, F found) {
		while (last - first > 1) {
			T sum = *first + *(last - 1);
			if (sum < target)
				++first;
			else if (sum > target)
				--last;
			else
				found(first, --last);
		}
	}
public:
	/* time: O(n), space: O(1) */
	vector<int> twoSum(const vector<int>& numbers, int target) {
		vector<int> ans;
		sortedTwoSum(numbers.begin(), numbers.end(), target, [&](auto x, auto y) {
			const int i = distance(numbers.begin(), x) + 1;
			const int j = distance(numbers.begin(), y) + 1;
			ans = {i, j};
		});
		return ans;
	}
};
