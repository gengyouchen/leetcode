class Solution {
private:
	static void radixSort(vector<string>& A) {
		const int n = A.size();
		vector<string> B(n);
		for (int d = 2; d >= 0; --d) {
			array<int, 26> count = {};
			for (int i = 0; i < n; ++i) {
				const int digit = A[i][d] - 'A';
				++count[digit];
			}
			partial_sum(count.begin(), count.end(), count.begin());
			for (int i = n - 1; i >= 0; --i) {
				const int digit = A[i][d] - 'A';
				B[--count[digit]] = A[i];
			}
			swap(A, B);
		}
	}
public:
	/* time: O(n), space: O(n), where n = # of tickets */
	static vector<string> findItinerary(const vector<vector<string>>& tickets) {
		unordered_map<string, vector<string>> adjLists;
		for (const auto& ticket : tickets)
			adjLists[ticket[0]].push_back(ticket[1]);

		for (auto& it : adjLists) {
			auto& adjList = it.second;
			radixSort(adjList);
			reverse(adjList.begin(), adjList.end());
		}

		vector<string> ans;

		using F = function<void(const string&)>;
		F dfs = [&](const auto& u) {
			auto& adjList = adjLists[u];
			while (!adjList.empty()) {
				const auto v = adjList.back();
				adjLists[u].pop_back();
				dfs(v);
			}
			ans.push_back(u);
		};

		dfs("JFK");
		reverse(ans.begin(), ans.end());
		return ans;
	}
};
