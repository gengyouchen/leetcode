class Solution {
private:
	struct Event {
		int t;
		bool begin;
		Event(bool begin, int t) : begin(begin), t(t) {}
	};
public:
	/* time: O(n*log(n)), space: O(n) */
	int minMeetingRooms(const vector<Interval>& intervals) {
		vector<Event> events;
		for (const auto& interval : intervals) {
			events.emplace_back(true, interval.start);
			events.emplace_back(false, interval.end);
		}

		auto comp = [](const Event& a, const Event& b) {
			if (a.t == b.t && a.begin != b.begin)
				return !a.begin;
			else
				return a.t < b.t;
		};
		sort(events.begin(), events.end(), comp);

		int nRoomUsed = 0, ans = 0;
		for (const auto& event : events) {
			if (event.begin)
				++nRoomUsed;
			else
				--nRoomUsed;
			ans = max(ans, nRoomUsed);
		}
		return ans;
	}
};
