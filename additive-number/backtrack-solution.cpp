class Solution {
private:
	template <class I>
	static bool isEqual(const I& x, const I& y, const I& z, const I& w) {
		const int xSize = distance(x, y), ySize = distance(y, z), zSize = distance(z, w);
		bool carry = false;
		for (int i = 0; i < zSize; ++i) {
			const int expected = *(z + zSize - i - 1) - '0';
			int digit = carry ? 1 : 0;
			if (i < xSize)
				digit += *(x + xSize - i - 1) - '0';
			if (i < ySize)
				digit += *(y + ySize - i - 1) - '0';
			carry = (digit >= 10);
			if (carry)
				digit -= 10;
			if (expected != digit)
				return false;
		}
		return !carry;
	}
	template <class I>
	static bool isAdditiveNumber(const I& first, const I& second, const I& rest, const I& last) {
		auto x = first, y = second, z = rest;
		while (z != last) {
			const int xSize = distance(x, y), ySize = distance(y, z), restSize = distance(z, last);
			if ((xSize > 1 && *x == '0') || (ySize > 1 && *y == '0'))
				return false;
			int zSize = max(xSize, ySize);
			if ((zSize > 1 && *z == '0') || (zSize > restSize))
				return false;
			if (!isEqual(x, y, z, z + zSize)) {
				++zSize;
				if ((zSize > 1 && *z == '0') || (zSize > restSize))
					return false;
				if (!isEqual(x, y, z, z + zSize))
					return false;
			}
			x = y, y = z, z += zSize;
		}
		return true;
	}
public:
	/* time: O(n^3), space: O(1) */
	static bool isAdditiveNumber(const string& num) {
		if (num.empty())
			return false;
		for (auto second = num.begin() + 1; second != num.end(); ++second) {
			for (auto rest = second + 1; rest != num.end(); ++rest) {
				if (isAdditiveNumber(num.begin(), second, rest, num.end())) 
					return true;
			}
		}
		return false;
	}
};
