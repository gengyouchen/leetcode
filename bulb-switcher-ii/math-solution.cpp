class Solution {
public:
	/* time: O(1), space: O(1) */
	static int flipLights(int n, int m) {
		/*
		 * The answer of n > 3 will be the same as n == 3
		 * <Proof>
		 * Let the binary state of our 4 buttons are a, b, c, d.
		 * If its state = 1, it means that button is pressed odd times (i.e. flipped)
		 * If its state = 0, it means that button is pressed even times (i.e. not flipped)
		 *
		 * We can use a, b, c, d to express every light's state:
		 * light[1] = a ^ b ^ d
		 * light[2] = a ^ c
		 * light[3] = a ^ b
		 * light[4] = a ^ c ^ d == light[1] ^ light[2] ^ light[3]
		 * light[5] = a ^ b == light[3]
		 * light[6] = a ^ c == light[2]
		 * Notice that once the state of the 1st, 2nd, 3rd lights are determined,
		 * the state of the 4th, 5th, 6th lights are also determined.
		 *
		 * Moreover, once the states of the first 6 lights are determined,
		 * the rest of the lights are just repeated their states.
		 * light[7] = a ^ b ^ d == light[1]
		 * light[8] = a ^ c == light[2]
		 * light[9] = a ^ b == light[3]
		 * light[10] = a ^ c ^ d == light[4]
		 * light[11] = a ^ b == light[5]
		 * light[12] = a ^ c == light[6]
		 */
		n = min(n, 3);
		bool state[8] = {};

		/*
		 * We only need to consider 0 <= m <= 4
		 * <Proof>
		 * m == 0 means: Doing nothing
		 * m == 1 means: Pressing any one button once
		 * m == 2 means: (1) Pressing any 2 distinct buttons once, or (2) is equivalent to m == 0
		 * m == 3 means: (1) Pressing any 3 distinct buttons once, or (2) is equivalent to m == 1
		 * m == 4 means: (1) Pressing all 4 distinct buttons once, or (2) is equivalent to m == 2
		 * m == 5 is equivalent to the m == 3
		 * m == 6 is equivalent to the m == 4
		 * m == 7 is equivalent to the m == 5
		 * m == 8 is equivalent to the m == 6
		 * m == 9 is equivalent to the m == 7
		 * m == 10 is equivalent to the m == 8
		 * m == 11 is equivalent to the m == 9
		 * m == 12 is equivalent to the m == 10
		 */
		m = (m <= 4) ? m : (m % 2) ? 3 : 4;
		const array<int, 1> press0 {0x0};
		const array<int, 4> press1 {0x1, 0x2, 0x4, 0x8};
		const array<int, 7> press2 {0x0, 0x3, 0x5, 0x6, 0x9, 0xA, 0xC};
		const array<int, 8> press3 {0x1, 0x2, 0x4, 0x7, 0x8, 0xB, 0xD, 0xE};
		const array<int, 8> press4 {0x0, 0x3, 0x5, 0x6, 0x9, 0xA, 0xC, 0xF};

		auto mark = [&](const auto& press) {
			for (int bits : press) {
				const int a = bits & 1, b = (bits >> 1) & 1, c = (bits >> 2) & 1, d = (bits >> 3) & 1;
				const int light1 = a ^ b ^ d, light2 = a ^ c, light3 = a ^ b;
				if (n == 0)
					state[0] = true;
				else if (n == 1)
					state[light1] = true;
				else if (n == 2)
					state[(light2 << 1) + light1] = true;
				else if (n == 3)
					state[(light3 << 2) + (light2 << 1) + light1] = true;
			}
		};
		if (m == 0)
			mark(press0);
		else if (m == 1)
			mark(press1);
		else if (m == 2)
			mark(press2);
		else if (m == 3)
			mark(press3);
		else if (m == 4)
			mark(press4);

		int ans = 0;
		for (int i = 0; i < 8; ++i) {
			if (state[i])
				++ans;
		}
		return ans;
	}
};
