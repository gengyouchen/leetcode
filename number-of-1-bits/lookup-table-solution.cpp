#define R2(n)   (n),   (n + 1),   (n + 1),   (n + 2)
#define R4(n) R2(n), R2(n + 1), R2(n + 1), R2(n + 2)
#define R6(n) R4(n), R4(n + 1), R4(n + 1), R4(n + 2)
#define R8(n) R6(n), R6(n + 1), R6(n + 1), R6(n + 2)

const unsigned char BitCountTable256[] = { R8(0) };

class Solution {
public:
	/* time: O(1), space: O(1) */
	int hammingWeight(uint32_t n) {
		return
			(BitCountTable256[n & 0xff]) +
			(BitCountTable256[(n >> 8) & 0xff]) +
			(BitCountTable256[(n >> 16) & 0xff]) +
			(BitCountTable256[(n >> 24) & 0xff]);
	}
};
