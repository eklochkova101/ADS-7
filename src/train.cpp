// Copyright 2026 NNTU-CS
#include "train.h"

Train::Train() : countOp(0), first(nullptr) {}

int Train::getOpCount() {
  return countOp;
}

void Train::addCar(bool light) {
  Car* car = new Car{light, nullptr, nullptr};
  if (!first) {
    first = car;
    car->next = car->prev = car;
  }
  else {
    car->next = first;
    car->prev = first->prev;
    first->prev->next = car;
    first->prev = car;
  }
}

int Train::getLength() {
  if (!first) return 0;
  countOp = 0;
  bool startState = first->light;
  first->light = true;
  Car* scout = first;
  while (true) {
    int dist = 0;
    do {
      scout = scout->next;
      countOp++;
      dist++;
    } while (!scout->light);
    scout->light = false;
    int backSteps = dist;
    while (backSteps--) {
      scout = scout->prev;
      countOp++;
    }
    if (!first->light) return dist;
  }
}
