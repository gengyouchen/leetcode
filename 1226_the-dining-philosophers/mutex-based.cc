class DiningPhilosophers {
 public:
  void wantsToEat(int philosopher, function<void()> pickLeftFork,
                  function<void()> pickRightFork, function<void()> eat,
                  function<void()> putLeftFork, function<void()> putRightFork) {
    pickUp(philosopher);

    pickLeftFork();
    pickRightFork();
    eat();
    putLeftFork();
    putRightFork();

    putDown(philosopher);
  }

 private:
  mutex fork[5];
  void pickUp(int i) {
    if (i % 2) {
      fork[(i + 1) % 5].lock();
      fork[(i + 4) % 5].lock();
    } else {
      fork[(i + 4) % 5].lock();
      fork[(i + 1) % 5].lock();
    }
  }
  void putDown(int i) {
    fork[(i + 1) % 5].unlock();
    fork[(i + 4) % 5].unlock();
  }
};
