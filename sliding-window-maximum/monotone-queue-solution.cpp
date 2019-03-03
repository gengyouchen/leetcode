template <class T>
class MonoQueue {
private:
	queue<T> all;
	deque<T> mono;
public:
	void push_back(const T& val) {
		while (!mono.empty() && val > mono.back())
			mono.pop_back();
		mono.push_back(val);
		all.push(val);
	}
	void pop_front() {
		if (all.front() == mono.front())
			mono.pop_front();
		all.pop();
	}
	T max() const { return mono.front(); }
	int size() const { return all.size(); }
};

class Solution {
public:
	/* time: O(n), space: O(k) */
	vector<int> maxSlidingWindow(const vector<int>& nums, int k) {
		MonoQueue<int> q;
		vector<int> ans;
		for (int num : nums) {
			q.push_back(num);
			if (q.size() == k) {
				ans.push_back(q.max());
				q.pop_front();
			}
		}
		return ans;
	}
};
