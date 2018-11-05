struct OddEvenIterator {
	using iterator_category = bidirectional_iterator_tag;
	using value_type = int;
	using difference_type = int;
	using pointer = int*;
	using reference = int&;

	int *p, i, n;
	OddEvenIterator(int *p, int i, int n) : p(p), i(i), n(n) {}
	int& operator*() { return p[(i * 2 + 1) % (n | 1)]; }

	bool operator==(const OddEvenIterator& rhs) const { return (p == rhs.p) && (i == rhs.i) && (n == rhs.n); }
	bool operator!=(const OddEvenIterator& rhs) const { return (p != rhs.p) || (i != rhs.i) || (n != rhs.n); }
	OddEvenIterator& operator++() { ++i; return *this; }
	OddEvenIterator& operator--() { --i; return *this; }
	OddEvenIterator operator++(int) { auto tmp(*this); ++i; return tmp; }
	OddEvenIterator operator--(int) { auto tmp(*this); --i; return tmp; }
};

class Solution {
public:
	/* time: O(n), space: O(1) auxiliary (i.e. does not count input & output itself) */
	void wiggleSort(vector<int>& nums) {
		const int n = nums.size();
		const auto mid = nums.begin() + n / 2;
		nth_element(nums.begin(), mid, nums.end());
		const int median = *mid;

		auto L = OddEvenIterator(nums.data(), 0, n);
		auto R = OddEvenIterator(nums.data(), n, n);
		L = partition(L, R, [&](int num) { return num > median; });
		partition(L, R, [&](int num) { return num == median; });
	}
};
