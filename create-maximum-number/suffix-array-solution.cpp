class SuffixArray {
private:
	vector<int> SA, order;
public:
	SuffixArray(const string& s) : SA(s.size()), order(s.size()) {
		const int n = s.size();
		vector<int> prevRank(n), nextRank(n), tmp(n), count(max(256, n));
		iota(SA.begin(), SA.end(), 0);
		copy(s.begin(), s.end(), prevRank.begin());

		auto countingSort = [&](auto rank) {
			fill(count.begin(), count.end(), 0);
			for (int i = 0; i < n; ++i)
				++count[rank(SA[i])];
			partial_sum(count.begin(), count.end(), count.begin());
			for (int i = n - 1; i >= 0; --i)
				tmp[--count[rank(SA[i])]] = SA[i];
			swap(tmp, SA);
		};

		/* Use the prefix-doubling technique to sort suffixes in O(n*log(n)) time */
		int len = 2;
		auto firstHalfRank = [&](int x) { return prevRank[x]; };
		auto secondHalfRank = [&](int x) { return (x + len / 2 < n) ? prevRank[x + len / 2] : 0; };
		auto comp = [&](int x, int y) {
			return (firstHalfRank(x) != firstHalfRank(y)) ?
				(firstHalfRank(x) < firstHalfRank(y)) : (secondHalfRank(x) < secondHalfRank(y));
		};
		while (len <= n) {
			countingSort(secondHalfRank), countingSort(firstHalfRank);

			int k = 0;
			nextRank[SA[0]] = k;
			for (int i = 1; i < n; ++i) {
				if (comp(SA[i - 1], SA[i]))
					++k;
				nextRank[SA[i]] = k;
			}
			swap(prevRank, nextRank), len *= 2;

			if (k == n - 1)
				break; /* every suffix has different rank, so no need to sort further */
		}

		for (int i = 0; i < n; ++i)
			order[SA[i]] = i;
	}
	int getOrder(int start) const { return order[start]; }
};

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
		string str(m + n + 1, '\0');
		for (int i = 0; i < m; ++i)
			str[i] = '0' + nums1[i];
		for (int i = 0; i < n; ++i)
			str[m + 1 + i] = '0' + nums2[i];
		SuffixArray sa(str);

		vector<int> ans(m + n);
		int i = 0, j = 0;
		for (int d = 0; d < m + n; ++d) {
			if (i == m)
				ans[d] = nums2[j++];
			else if (j == n)
				ans[d] = nums1[i++];
			else
				ans[d] = sa.getOrder(i) < sa.getOrder(m + 1 + j) ? nums2[j++] : nums1[i++];
		}
		return ans;
	}
public:
	/* time: O(k * (m+n) * log(m+n)), space: O(m+n) */
	static vector<int> maxNumber(const vector<int>& nums1, const vector<int>& nums2, int k) {
		const int m = nums1.size(), n = nums2.size();
		vector<int> ans;
		for (int k1 = max(k - n, 0); k1 <= min(k, m); ++k1)
			ans = max(ans, merge(maxNumber(nums1, k1), maxNumber(nums2, k - k1)));
		return ans;
	}
};
