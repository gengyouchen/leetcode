// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
private:
	template <class T, class F>
	T lowestTrue(T min, T max, F cond) {
		while (min < max) {
			auto it = min + (max - min) / 2;
			if (cond(it) == true)
				max = it;
			else
				min = it + 1;
		}
		return min;
	}
public:
	/* time: O(log(n)), space: O(1) */
	int firstBadVersion(int n) {
		return lowestTrue(1, n, [](int i) { return isBadVersion(i); });
	}
};
