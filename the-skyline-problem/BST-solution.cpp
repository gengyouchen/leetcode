class Solution {
private:
	struct Event {
		int h, t;
		bool begin;
		Event(bool begin, int t, int h) : begin(begin), t(t), h(h) {}
	};
public:
	/* time: O(n*log(n)), space: O(n), where n=len(buildings) */
	vector<pair<int, int>> getSkyline(const vector<vector<int>>& buildings) {
		if (buildings.empty())
			return {};

		vector<Event> events;
		for (const auto& b : buildings) {
			const int t0 = b[0], t1 = b[1], h = b[2];
			events.emplace_back(true, t0, h);
			events.emplace_back(false, t1, h);
		}

		auto comp = [](const Event& a, const Event& b) {
			if (a.t != b.t)
				return a.t < b.t;
			else if (a.begin != b.begin)
				return a.begin;
			else
				return a.h < b.h;
		};
		sort(events.begin(), events.end(), comp);

		vector<pair<int, int>> ans;
		int t = -1;
		multiset<int> h;
		h.insert(0);
		for (const auto& event : events) {
			if (t != -1 && t != event.t) {
				if (ans.empty() || ans.back().second != *h.rbegin())
					ans.emplace_back(t, *h.rbegin());
			}

			t = event.t;
			if (event.begin)
				h.insert(event.h);
			else
				h.erase(h.find(event.h));
		}
		if (ans.back().second != *h.rbegin())
			ans.emplace_back(t, *h.rbegin());
		return ans;
	}
};
