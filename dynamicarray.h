// Copyright 2025 Abby Holdcraft
// Header for Dynamic Array
#include <ostream>
using std::ostream;
#ifndef _DYNAMICARRAY_H_
#define _DYNAMICARRAY_H_

class DynamicArray {
 public:
  // Creates new DynamicArray
  explicit DynamicArray(int size = 1);
  // Copies existing DynamicArray to new DynamicArray
  DynamicArray(const DynamicArray &other);
  // Class destructor
  ~DynamicArray();

  // = Operator
  DynamicArray& operator = (DynamicArray const& obj);
  // == Operator
  bool operator == (DynamicArray const& obj);
  // != Operator
  bool operator != (DynamicArray const& obj);
  // << Operator
  friend ostream& operator << (ostream& where_to, const DynamicArray& array);
  // version that allows one to use the operator in a non-constant setting
  // to update the values in the array
  int& operator[](int i) {
    if ( i >= 0 && i < size_ ) return values_[i];
    if ( i < 0 ) return values_[0];
    return values_[size_ - 1];
  }

  // version that allows one to use the operator on a constant array
  // returning copies of a value in the array
  int operator[](int i) const {
    if ( i >= 0 && i < size_ ) return values_[i];
    if ( i < 0 ) return values_[0];
    return values_[size_ - 1];
  }

  // Methods

  // Returns delimiter char
  static char GetDelimeter();
  // Sets delimiter char to param
  static void SetDelimeter(char delim);
  // Returns array size
  int GetSize();
  // Sets array size.
  // If copy == true, copies all values of original array to new array
  // If copy == false, does not copy values
  void SetSize(int newSize, bool copy = true);
  // Returns true if all array values are unique
  bool AllUnique();
  // removes all instances of param
  int RemoveAll(int value);
  // replaces all instances of find with replace
  int FindAndReplace(int find, int replace);
  // Removes all but first instance of value
  void RemoveDuplicates();
  // Sorts array by descending or ascending order, depending on bool param
  void Sort(bool descending = false);
  // Adds new value at specified index, default adds to the end
  void Add(int value, int index = -1);
  // Adds new value to start of array
  void Prepend(int value);
  // Adds new value to end of array
  void Append(int value);
  // Concatenates two arrays
  void Concat(DynamicArray const& array);



 private:
  int size_;
  int * values_;
  static char delimiter_;

  // Removes all but first instance of parameter
  void RemoveDuplicates(int value);
};

#endif  // DYNAMICARRAY_H_
