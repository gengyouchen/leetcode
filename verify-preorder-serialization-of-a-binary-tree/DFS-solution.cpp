class Solution {
private:
	typedef function<bool()> F;
public:
	/* time: O(n), space: O(n) */
	bool isValidSerialization(const string& preorder) {
		auto it = preorder.begin();
		F dfs = [&]() {
			/* check if serialization is too short */ 
			if (it == preorder.end())
				return false;

			if (*it == ',')
				++it;

			if (*it == '#')
				++it;
			else {
				while (isdigit(*it))
					++it;
				if (!dfs())
					return false;
				if (!dfs())
					return false;
			}
			return true;
		};

		/* serialization is not too short && not too long */ 
		return dfs() && (it == preorder.end());
	}
};
