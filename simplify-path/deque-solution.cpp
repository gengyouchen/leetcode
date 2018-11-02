class Solution {
public:
	/* time: O(n), space: O(n) */
	string simplifyPath(const string& path) {
		deque<string> pwd;
		auto cd = [&](const string& dir) {
			if (dir.empty() || dir == ".")
				return;
			if (dir == "..") {
				if (!pwd.empty())
					pwd.pop_back();
				return;
			}
			pwd.push_back(dir);
		};

		auto L = path.begin();
		for (auto R = path.begin(); R != path.end(); ++R)
			if (*R == '/')
				cd(string(L, R)), L = R + 1;
		cd(string(L, path.end()));

		string ans;
		for (const string& dir : pwd)
			ans.push_back('/'), ans += dir;
		return ans.empty() ? "/" : ans;
	}
};
