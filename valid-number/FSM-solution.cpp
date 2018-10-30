class Solution {
private:
	enum State {
		LEADING_SPACE, FRACTION_SIGN, FRACTION_DIGIT, FRACTION_POINT,
		FRACTION_POINT_AFTER_DIGIT, FRACTION_DIGIT_AFTER_POINT,
		EXPONENT_BEGIN, EXPONENT_SIGN, EXPONENT_DIGIT, TRAILING_SPACE
	};
public:
	/* time: O(n), space: O(1) */
	bool isNumber(const string& s) {
		State prev = LEADING_SPACE;
		for (char c : s)
			switch (prev) {
			case LEADING_SPACE:
				if (c == ' ') prev = LEADING_SPACE;
				else if (c == '+' || c == '-') prev = FRACTION_SIGN;
				else if (isdigit(c)) prev = FRACTION_DIGIT;
				else if (c == '.') prev = FRACTION_POINT;
				else return false;
				break;
			case FRACTION_SIGN:
				if (isdigit(c)) prev = FRACTION_DIGIT;
				else if (c == '.') prev = FRACTION_POINT;
				else return false;
				break;
			case FRACTION_DIGIT:
				if (isdigit(c)) prev = FRACTION_DIGIT;
				else if (c == '.') prev = FRACTION_POINT_AFTER_DIGIT;
				else if (c == 'e') prev = EXPONENT_BEGIN;
				else if (c == ' ') prev = TRAILING_SPACE;
				else return false;
				break;
			case FRACTION_POINT:
				if (isdigit(c)) prev = FRACTION_DIGIT_AFTER_POINT;
				else return false;
				break;
			case FRACTION_POINT_AFTER_DIGIT:
			case FRACTION_DIGIT_AFTER_POINT:
				if (isdigit(c)) prev = FRACTION_DIGIT_AFTER_POINT;
				else if (c == 'e') prev = EXPONENT_BEGIN;
				else if (c == ' ') prev = TRAILING_SPACE;
				else return false;
				break;
			case EXPONENT_BEGIN:
				if (c == '+' || c == '-') prev = EXPONENT_SIGN;
				else if (isdigit(c)) prev = EXPONENT_DIGIT;
				else return false;
				break;
			case EXPONENT_SIGN:
				if (isdigit(c)) prev = EXPONENT_DIGIT;
				else return false;
				break;
			case EXPONENT_DIGIT:
				if (isdigit(c)) prev = EXPONENT_DIGIT;
				else if (c == ' ') prev = TRAILING_SPACE;
				else return false;
				break;
			case TRAILING_SPACE:
				if (c == ' ') prev = TRAILING_SPACE;
				else return false;
				break;
			}
		return (prev == FRACTION_DIGIT) ||
			(prev == FRACTION_POINT_AFTER_DIGIT) ||
			(prev == FRACTION_DIGIT_AFTER_POINT) ||
			(prev == EXPONENT_DIGIT) ||
			(prev == TRAILING_SPACE);
	}
};
