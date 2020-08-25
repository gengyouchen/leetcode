class DiningPhilosophers {
 public:
  void wantsToEat(int philosopher, function<void()> pickLeftFork,
                  function<void()> pickRightFork, function<void()> eat,
                  function<void()> putLeftFork, function<void()> putRightFork) {
    monitor.pickUp(philosopher);

    pickLeftFork();
    pickRightFork();
    eat();
    putLeftFork();
    putRightFork();

    monitor.putDown(philosopher);
  }

 private:
  class DiningPhilosophersMonitor {
   public:
    void pickUp(int i) {
      unique_lock<mutex> lck(monitor_lock);

      auto is_thinking = [&]() { return state[i] == THINKING; };
      self[i].wait(lck, is_thinking);

      state[i] = HUNGRY;
      test(i);

      auto is_eating = [&]() { return state[i] == EATING; };
      self[i].wait(lck, is_eating);
    }

    void putDown(int i) {
      unique_lock<mutex> lck(monitor_lock);

      state[i] = THINKING;
      self[i].notify_all();

      test((i + 1) % 5);
      test((i + 4) % 5);
    }

   private:
    mutex monitor_lock;
    condition_variable self[5];
    enum { THINKING, HUNGRY, EATING } state[5] = {};
    void test(int i) {
      if (state[(i + 1) % 5] != EATING && state[(i + 4) % 5] != EATING &&
          state[i] == HUNGRY) {
        state[i] = EATING;
        self[i].notify_all();
      }
    }
  };

  DiningPhilosophersMonitor monitor;
};
