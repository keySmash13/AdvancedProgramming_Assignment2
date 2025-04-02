// Copyright 2025 Abby Holdcraft and Jacob Sherer
#include<iostream>
#include"dynamicarray.h"

// See header file for notes on function implementation!

char DynamicArray::delimiter_ = ' ';

DynamicArray::DynamicArray(int size) {
  if (size < 1)
    size_ = 1;
  else
    size_ = size;
  values_ = new int[size_];
  for ( int i = 0; i < size_; i++ )
    values_[i] = 0;
}
DynamicArray::DynamicArray(const DynamicArray &other) {
  size_ = other.size_;
  values_ = new int[size_];
  for ( int i = 0; i < size_; i++ )
    values_[i] = other.values_[i];
}
DynamicArray::~DynamicArray() {
  // Destructor
}
//HELP!!!!
DynamicArray& DynamicArray::operator = (DynamicArray const& obj) {
	if ( *this == obj )
  	return *this;
	return DynamicArray(obj);
  // size_ = obj.size_;
  // values_ = obj.values_;
}
bool DynamicArray::operator == (DynamicArray const& obj) {
  if ( size_ != obj.size_ )
    return false;
  for ( int i = 0; i < size_; i++)
    if ( values_[i] != obj.values_[i])
      return false;
  return true;
}
ostream& operator << (ostream& where_to, const DynamicArray& array) {
  for ( int i = 0; i < array.size_-1; i++)
    where_to << array.values_[i] << array.delimiter_;
  where_to << array.values_[array.size_ - 1] << std::endl;
	return where_to;
}
char DynamicArray::GetDelimeter() {
  return delimiter_;
}
void DynamicArray::SetDelimeter (char delim) {
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
bool DynamicArray::AllUnique() {
  for ( int i = 0; i < size_; i++ )
    for ( int j = i+1; j < size_; j++)
      if ( values_[i] == values_[j] )
        return false;
  return true;
}
int DynamicArray::RemoveAll(int value) {
  // Count number of values being removed
  int count = 0;
  for ( int i = 0; i < size_; i++ )
    if ( values_[i] == value )
      count++;
  if (count == size_) {
    *this = DynamicArray(1);
    return count;
  }
  // Init array of correct size and transfer values
  int index = 0;
  for ( int i = 0; i < size_; i++ ) {
    if ( values_[i] != value ) {
      values_[index++] = values_[i];
		}
	}
	SetSize(size_-count);
  return count;
}
int DynamicArray::FindAndReplace(int find, int replace) {
  int how_many = 0;
  for ( int i = 0; i < size_; i++ ){
    if ( values_[i] == find ) {
      values_[i] = replace;
      how_many++;
    }
  }
	return how_many;
}
void DynamicArray::RemoveDuplicates() {
	for ( int i = 0; i < size_; i++ ) {
		if ( AllUnique() )
			return;
		RemoveDuplicates(values_[i]);
	}
}
void DynamicArray::RemoveDuplicates(int value) {
	bool first = true;
	int index = 0;
	for ( int i = 0; i < size_; i++ ) {
		if ( values_[i] == value ) {
			if (first) {
				first = false;
				values_[index++] = values_[i];
			}
		}
		else {
			values_[index++] = values_[i];
		}
	}
	SetSize(index);
}
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
  if (index < 0 || index >= size_)
    index = size_ - 1; // Invalid index, only from 0 to size
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
  Add(value);
}
