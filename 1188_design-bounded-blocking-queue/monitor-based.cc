class BoundedBlockingQueue {
 public:
  BoundedBlockingQueue(int capacity) : n(capacity) {}

  void enqueue(int element) {
    unique_lock<mutex> lck(monitor_lock);

    auto is_not_full = [&]() { return q.size() < n; };
    non_full.wait(lck, is_not_full);

    q.push(element);
    non_empty.notify_all();
  }

  int dequeue() {
    unique_lock<mutex> lck(monitor_lock);

    auto is_not_empty = [&]() { return !q.empty(); };
    non_empty.wait(lck, is_not_empty);

    const int element = q.front();
    q.pop();
    non_full.notify_all();
    return element;
  }

  int size() {
    unique_lock<mutex> lck(monitor_lock);

    return q.size();
  }

 private:
  mutex monitor_lock;
  condition_variable non_empty, non_full;
  const int n;
  queue<int> q;
};
