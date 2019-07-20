class Solution {
private:
	static vector<int> maxNumber(const vector<int>& nums, int k) {
		const int n = nums.size(), maxSkippable = n - k;
		vector<int> ans;
		int nSkipped = 0;
		for (int num : nums) {
			while (nSkipped < maxSkippable && !ans.empty() && ans.back() < num)
				ans.pop_back(), ++nSkipped;
			ans.push_back(num);
			if (nSkipped == maxSkippable && ans.size() == k)
				break;
		}
		ans.resize(k);
		return ans;
	}
	static vector<int> merge(const vector<int>& nums1, const vector<int>& nums2) {
		const int m = nums1.size(), n = nums2.size();
		auto it1 = nums1.begin(), it2 = nums2.begin();
		vector<int> ans(m + n);
		for (int& out : ans)
			out = lexicographical_compare(it1, nums1.end(), it2, nums2.end()) ? *it2++ : *it1++;
		return ans;
	}
public:
	/* time: O(k * (m+n) * min(m,n)), space: O(m+n) */
	static vector<int> maxNumber(const vector<int>& nums1, const vector<int>& nums2, int k) {
		const int m = nums1.size(), n = nums2.size();
		vector<int> ans;
		for (int k1 = max(k - n, 0); k1 <= min(k, m); ++k1)
			ans = max(ans, merge(maxNumber(nums1, k1), maxNumber(nums2, k - k1)));
		return ans;
	}
};
