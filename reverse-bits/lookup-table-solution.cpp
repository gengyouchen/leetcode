#define R2(n)   (n),   (0x80 | n),   (0x40 | n),   (0xc0 | n)
#define R4(n) R2(n), R2(0x20 | n), R2(0x10 | n), R2(0x30 | n)
#define R6(n) R4(n), R4(0x08 | n), R4(0x04 | n), R4(0x0c | n)
#define R8(n) R6(n), R6(0x02 | n), R6(0x01 | n), R6(0x03 | n)

const unsigned char BitReverseTable256[] = { R8(0x00) };

class Solution {
public:
	/* time: O(1), space: O(1) */
	uint32_t reverseBits(uint32_t n) {
		return
			(BitReverseTable256[n & 0xff] << 24) |
			(BitReverseTable256[(n >> 8) & 0xff] << 16) |
			(BitReverseTable256[(n >> 16) & 0xff] << 8) |
			(BitReverseTable256[(n >> 24) & 0xff]);
	}
};
