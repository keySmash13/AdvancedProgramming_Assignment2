#ifndef _DYNAMICARRAY_H_
#define _DYNAMICARRAY_H_

class DynamicArray {
 public:

  // Constructors and Destructors

  DynamicArray(int size = 1);  //Init all other values = 0. 
  DynamicArray(const DynamicArray &other);  // copies existing class to new class 
  ~DynamicArray();  // Class destructor



  // Operators

  // TODO figure out how to actually create operators lol
  void operator=(DynamicArray const& obj);
  bool operator==(DynamicArray const& obj);
  // void friend operator<<(DynamicArray const& obj);

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
  char GetDelimiter();
  // Sets delimiter char to param
  void SetDelimiter (char delim);
  // Returns array size
  int GetSize();
  // Sets array size.
  // If copy == true, copies all values of original array to new array
  // If copy == false, does not copy values
  int SetSize(int size, bool copy = true);  // if copy == true, copy all values that fit into new array, excess values default = 0.
  // Returns true if all array values are unique
  bool AllUnique();
  // removes all instances of param
  void RemoveAll(int value);
  // replaces all instances of find with replace
  void FindAndReplace(int find, int replace);
  // Removes all but first instance of value
  void RemoveDuplicates(int value);
  // Sorts array by descending or ascending order, depending on bool param
  void Sort(bool descending);

  /*
  NOTES ON ADD/REMOVE:
  When add/removing values, remember to shift all values over to create or remove space.
    AKA:
    RemoveAll(3) on int[] x = {1, 2, 3, 3, 4} has to shift the pointer to 4 left by 2 spaces!
    Add(&x, 4) will shift all values at index 4, 5, 6, etc to the next index.
  If array is full when adding, increase array size by 1 to accomodate new value
  */

  // Adds new value at specified index, default adds to the end
  void Add(int &value, int index = -1) {  // Check that index is valid, if not default value of index is instance.size_
    if ( index < 1 ) index = size_;
  }
  // Adds new value to start of array
  void AddFirst(int &value);
  // Adds new value to end of array
  void AddLast(int &value); // No shifting needed


 private:
  int size_;
  int * values_;
  static char delimiter_; // (for separator used by <<)
};

#endif
