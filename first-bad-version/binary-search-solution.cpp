// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
private:
	template <class I, class F>
	I findFirstTrue(I first, I last, F cond) {
		while (first != last) {
			I mid = first + (last - first) / 2;
			if (cond(mid))
				last = mid;
			else
				first = mid + 1;
		}
		return first;
	}
public:
	int firstBadVersion(int n) {
		return findFirstTrue(1, n, isBadVersion);
	}
};
