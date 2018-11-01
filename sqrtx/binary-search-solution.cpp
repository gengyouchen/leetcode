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
	/* time: O(log(x)), space: O(1) */
	int mySqrt(int x) {
		if (x == 1)
			return 1;
		return lowestTrue(1, x, [&](long i) { return i * i > x; }) - 1;
	}
};
