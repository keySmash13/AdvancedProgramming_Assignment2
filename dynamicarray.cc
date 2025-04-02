// Copyright 2025 Abby Holdcraft and Jacob Sherer
#include<iostream>
#include"dynamicarray.h"

// See header file for notes on function implementation!

DynamicArray::DynamicArray(int size) {
  if (size < 1)
    size_ = 1;
  else
    size_ = size;
  values_ = new int[size_]{};
}
DynamicArray::DynamicArray(const DynamicArray &other) {}
DynamicArray::~DynamicArray() {}
char DynamicArray::GetDelimiter() {
  return delimiter_;
}
void DynamicArray::SetDelimiter (char delim) {
  // Ensures delimiter is not null or a control character
  if (delim != '\0' && !iscntrl(delim))
    delimiter_ = delim;
  else
    delimiter_ = ',';
}
int DynamicArray::GetSize() {
  return size_;
}
void DynamicArray::SetSize(int newSize, bool copy) {
  if (newSize < 1)
    return; // Ensure valid size
  int * newValues = new int[newSize]{}; // Allocate new memory, all set to 0

  if (copy) {
    int minSize;
    if (newSize < size_)
      minSize = newSize; // Getting smaller, cut off previous values
    else
      minSize = size_; // Getting bigger, copy all previous values
    for (int i = 0; i < minSize; ++i) {
      newValues[i] = values_[i];
    }
  }
  // Free up old memory and update pointer
  delete[] values_;
  values_ = newValues;
  size_ = newSize;
}
bool DynamicArray::AllUnique() {}
void DynamicArray::RemoveAll(int value) {}
void DynamicArray::FindAndReplace(int find, int replace) {}
void DynamicArray::RemoveDuplicates(int value) {}
void DynamicArray::Sort(bool descending) {
// Bubble sort
  for (int i = 0; i < (size_ - 1); ++i) {
    for (int j = 0; j < (size_ - i - 1); ++j) {
        if ((descending && values_[j] < values_[j + 1]) || 
            (!descending && values_[j] > values_[j + 1])) {
            std::swap(values_[j], values_[j + 1]); // Swap values
        }
    }
  }
}
void DynamicArray::Add(int &value, int index) {
  if (index < 0 || index > size_)
    return; // Invalid index, only from 0 to size
  SetSize((size_ + 1), true); // Increase array size by 1, keep existing values
  // Shift all values to the right starting from the end of the array
    for (int i = size_ - 1; i >= index; --i) {
      values_[i + 1] = values_[i];
    }
    values_[index] = value;
  }
void DynamicArray::Prepend(int &value) {
  Add(value, 0);
}
void DynamicArray::Append(int &value) {
  Add(value, (size_ - 1));
}