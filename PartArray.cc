#include "PartArray.h"

PartArray::PartArray() {
  size = 0;
}

PartArray::~PartArray() {
  for (int i=0; i<size; ++i) {
    delete elements[i];
  }
}

void PartArray::add(Participant* p) {
  if (size >= MAX_ARR) { return; }
  elements[size] = p;
  ++size;
}

Participant* PartArray::get(int index) { return elements[index]; }
int PartArray::getSize() { return size; }