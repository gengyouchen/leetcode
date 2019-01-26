class Solution {
public:
	/* time: O(m+n), space: O(1), where m = len(version1), n = len(version2) */
	int compareVersion(const string& version1, const string& version2) {
		int num1 = 0, num2 = 0;
		auto it1 = version1.begin(), it2 = version2.begin();
		while (it1 != version1.end() || it2 != version2.end()) {
			const bool endOfNum1 = (it1 == version1.end()) || (*it1 == '.');
			const bool endOfNum2 = (it2 == version2.end()) || (*it2 == '.');
			if (endOfNum1 && endOfNum2) {
				if (num1 > num2)
					return 1;
				if (num1 < num2)
					return -1;
				num1 = num2 = 0;
				if (it1 != version1.end())
					++it1;
				if (it2 != version2.end())
					++it2;
			}
			if (!endOfNum1)
				num1 = num1 * 10 + (int)(*it1++ - '0');
			if (!endOfNum2)
				num2 = num2 * 10 + (int)(*it2++ - '0');
		}
		if (num1 > num2)
			return 1;
		if (num1 < num2)
			return -1;
		return 0;
	}
};
