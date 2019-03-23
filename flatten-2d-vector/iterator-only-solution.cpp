class Vector2D {
private:
	/* As an added challenge, we try to code it using only iterators in C++ */
	vector<vector<int>>::const_iterator row, rowEnd;
	vector<int>::const_iterator col, colEnd;
	/* After constructor is called, LeetCode won't preserve the original 2D array, so we must make a copy. */
	vector<vector<int>> A;
public:
	/*
	 * time: O(n), space: O(1) auxiliary (i.e. does not count 2D array itself),
	 * where n = total # of elements in 2D array
	 */
	Vector2D(const vector<vector<int>> &v) : A(v) {
		row = A.begin(), rowEnd = A.end();
		if (row == rowEnd)
			return;
		col = row->begin(), colEnd = row->end();
		while (col == colEnd && ++row != rowEnd)
			col = row->begin(), colEnd = row->end();
	}
	/*
	 * time: O(r), space: O(1) auxiliary (i.e. does not count 2D array itself),
	 * where r = # of row in 2D array
	 */
	int next() {
		const int ans = *col++;
		while (col == colEnd && ++row != rowEnd)
			col = row->begin(), colEnd = row->end();
		return ans;
	}
	/* time: O(1), space: O(1) auxiliary (i.e. does not count 2D array itself) */
	bool hasNext() const {
		return row != rowEnd;
	}
};
