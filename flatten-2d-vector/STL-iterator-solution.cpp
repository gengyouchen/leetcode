class Vector2D {
private:
	using I = vector<vector<int>>::const_iterator;
	using J = vector<int>::const_iterator;
	I row, rowEnd;
	J col, colEnd;
public:
	/* time: O(1), space: O(1) */
	Vector2D(const vector<vector<int>>& v) {
		row = v.begin(), rowEnd = v.end();
		if (row != rowEnd)
			col = row->begin(), colEnd = row->end();
	}

	/* time: O(1) amortized, space: O(1) */
	int next() {
		if (!hasNext())
			return -1; /* failed */
		return *col++;
	}

	/* time: O(1) amortized, space: O(1) */
	bool hasNext() {
		while (row != rowEnd && col == colEnd && ++row != rowEnd)
			col = row->begin(), colEnd = row->end();
		return row != rowEnd;
	}
};
