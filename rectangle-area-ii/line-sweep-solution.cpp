#define MOD 1000000007
using LL = long long;
LL mod(LL x) { return (x % MOD + MOD) % MOD; }

class SegTree {
private:
	vector<int> reqs, lens, covered;
	void hook(int i, int j, int event, int x, int L, int R) {
		if (j < L || R < i) {
			/* no cover */
		} else if (i <= L && R <= j) {
			/* total cover */
			reqs[x] += event;
		} else {
			/* partial cover */
			const int mid = L + (R - L) / 2;
			hook(i, j, event, x * 2, L, mid);
			hook(i, j, event, x * 2 + 1, mid + 1, R);
		}

		if (reqs[x] > 0)
			covered[x] = lens[x];
		else if (L < R)
			covered[x] = covered[x * 2] + covered[x * 2 + 1];
		else
			covered[x] = 0;
	}
public:
	SegTree(const vector<int>& A) {
		const int n = A.size();
		int nLeaf = 1;
		while (nLeaf < n)
			nLeaf *= 2;
		reqs.resize(nLeaf * 2);
		lens.resize(nLeaf * 2);
		covered.resize(nLeaf * 2);

		copy(A.begin(), A.end(), lens.begin() + nLeaf);
		for (int x = nLeaf - 1; x > 0; --x)
			lens[x] = lens[x * 2] + lens[x * 2 + 1];
	}
	void add(int i, int j) {
		const int nLeaf = reqs.size() / 2;
		const int x = 1, L = 0, R = nLeaf - 1;
		return hook(i, j, +1, x, L, R);
	}
	void remove(int i, int j) {
		const int nLeaf = reqs.size() / 2;
		const int x = 1, L = 0, R = nLeaf - 1;
		return hook(i, j, -1, x, L, R);
	}
	int countCovered() const { return covered[1]; }
};

class Solution {
private:
	struct Event {
		int type, y, L, R;
		Event(int type, int y, int L, int R) : type(type), y(y), L(L), R(R) {}
	};
	static vector<int> getSortedEndpoints(const vector<vector<int>>& rectangles) {
		unordered_set<int> endpoints;
		for (const auto& rect : rectangles) {
			const int x0 = rect[0], x1 = rect[2];
			endpoints.insert(x0), endpoints.insert(x1);
		}

		vector<int> ret(endpoints.begin(), endpoints.end());
		sort(ret.begin(), ret.end());
		return ret;
	}
public:
	/* time: O(n*log(n)), space: O(n), where n = # of rectangles */
	static int rectangleArea(const vector<vector<int>>& rectangles) {
		/* Discretize rectangles in x-axis */
		const auto endpoints = getSortedEndpoints(rectangles);
		const int w = endpoints.size();

		unordered_map<int, int> endpoint2order;
		for (int i = 0; i < w; ++i)
			endpoint2order[endpoints[i]] = i;

		vector<Event> events;
		for (const auto& rect : rectangles) {
			const int x0 = rect[0], y0 = rect[1], x1 = rect[2], y1 = rect[3];
			const int L = endpoint2order[x0], R = endpoint2order[x1] - 1;
			events.emplace_back(+1, y0, L, R);
			events.emplace_back(-1, y1, L, R);
		}
		auto comp = [](const auto& a, const auto& b) {
			return (a.y != b.y) ? (a.y < b.y) : (a.type < b.type);
		};
		sort(events.begin(), events.end(), comp);

		/* Build the segment tree for discretized lengths */
		vector<int> A(w - 1);
		for (int i = 0; i < w - 1; ++i)
			A[i] = endpoints[i + 1] - endpoints[i];
		SegTree s(A);

		/* Perform the line sweep algorithm */
		LL ans = 0, lastY = -1;
		for (const auto& event : events) {
			if (lastY != -1 && event.y != lastY)
				ans = mod(ans + (event.y - lastY) * s.countCovered());
			lastY = event.y;

			if (event.type == +1)
				s.add(event.L, event.R);
			else
				s.remove(event.L, event.R);
		}
		return ans;
	}
};
