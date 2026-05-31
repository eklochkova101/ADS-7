// Copyright 2026 NNTU-CS
#include <iostream>
#include <vector>
#include "train.h"

int experiment_fixed(int n, bool state) {
  Train t;
  for (int i = 0; i < n; ++i)
    t.addCar(state);
  t.getLength();
  return t.getOpCount();
}
double experiment_random_avg(int n, int trials = 10) {
  double sum = 0.0;
  for (int t = 0; t < trials; ++t) {
    Train train;
    for (int i = 0; i < n; ++i)
      train.addCar(rand() % 2 == 0);
    train.getLength();
    sum += train.getOpCount();
  }
  return sum / trials;
}
int main() {
  srand(static_cast<unsigned>(time(nullptr)));
  const int MIN_N = 2;
  const int MAX_N = 30;
  const int STEP = 1;
  const int TRIALS = 10;
  std::vector<int> sizes;
  std::vector<double> ops_off, ops_on, ops_rand;
  for (int n = MIN_N; n <= MAX_N; n += STEP) {
    sizes.push_back(n);
    ops_off.push_back(experiment_fixed(n, false));
    ops_on.push_back(experiment_fixed(n, true));
    ops_rand.push_back(experiment_random_avg(n, TRIALS));
    std::cout << "n = " << n
      << "  off: " << ops_off.back()
      << "  on: " << ops_on.back()
      << "  rand: " << ops_rand.back() << std::endl;
  }
  return 0;
}
