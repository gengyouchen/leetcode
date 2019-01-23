// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
private:
	queue<char> unread7; /* space: O(1) because there're at most 7 unread chars */
	int safeRead4(char *buf, int n) {
		n = max(min(n, 4), 0);
		if (unread7.size() < n) {
			char buf4[4];
			const int len = read4(buf4);
			for (int i = 0; i < len; ++i)
				unread7.push(buf4[i]);
		}
		int count = 0;
		while (!unread7.empty() && count < n)
			++count, *buf++ = unread7.front(), unread7.pop();
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
