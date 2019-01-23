// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
private:
	int safeRead4(char *buf, int n) {
		n = max(min(n, 4), 0);
		char buf4[4];
		const int count = min(n, read4(buf4));
		copy_n(buf4, count, buf);
		return count;
	}
public:
	/* time: O(n), space: O(1) auxiliary (i.e. does not count output itself) */
	int read(char *buf, int n) {
		int count = 0;
		while (count < n) {
			const int len = safeRead4(buf, n - count);
			if (!len)
				break;
			buf += len, count += len;
		}
		return count;
	}
};
