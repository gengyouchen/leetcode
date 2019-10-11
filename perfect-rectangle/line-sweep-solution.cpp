class IntervalSet {
private:
	map<int, int> endpoints;
public:
	bool add(int L, int R) {
		const auto it = endpoints.upper_bound(L);
		if (it != endpoints.begin() && prev(it)->second != -1)
			return false;
		if (it != endpoints.end() && (it->first < R || it->second != +1))
			return false;
		++endpoints[L], --endpoints[R];

		if (!endpoints[L])
			endpoints.erase(L);
		if (!endpoints[R])
			endpoints.erase(R);
		return true;
	}
	bool remove(int L, int R) {
		const auto it = endpoints.upper_bound(L);
		if (it != endpoints.begin() && prev(it)->second != +1)
			return false;
		if (it != endpoints.end() && (it->first < R || it->second != -1))
			return false;
		--endpoints[L], ++endpoints[R];

		if (!endpoints[L])
			endpoints.erase(L);
		if (!endpoints[R])
			endpoints.erase(R);
		return true;
	}
	int countInterval() const { return endpoints.size() / 2; }
	int leftmost() const { return endpoints.begin()->first; }
	int rightmost() const { return endpoints.rbegin()->first; }
};

class Solution {
private:
	struct Event {
		int type, y, L, R;
		Event(int type, int y, int L, int R) : type(type), y(y), L(L), R(R) {}
	};
public:
	/* time: O(n*log(n)), space: O(n), where n = # of rectangles */
	static bool isRectangleCover(const vector<vector<int>>& rectangles) {
		int xMin = INT_MAX, xMax = INT_MIN;
		vector<Event> events;
		for (const auto& rect : rectangles) {
			const int x0 = rect[0], y0 = rect[1], x1 = rect[2], y1 = rect[3];
			xMin = min(xMin, x0), xMax = max(xMax, x1);
			events.emplace_back(+1, y0, x0, x1);
			events.emplace_back(-1, y1, x0, x1);
		}

		auto comp = [](const auto& a, const auto& b) {
			return (a.y != b.y) ? (a.y < b.y) : (a.type < b.type);
		};
		sort(events.begin(), events.end(), comp);

		IntervalSet s;
		int lastY = -1;
		for (const auto& event : events) {
			if (lastY != -1 && event.y != lastY) {
				if (s.countInterval() != 1 || s.leftmost() != xMin || s.rightmost() != xMax)
					return false;
			}
			lastY = event.y;
			if (event.type == +1) {
				if (!s.add(event.L, event.R))
					return false;
			} else {
				if (!s.remove(event.L, event.R))
					return false;
			}
		}
		return true;
	}
};
