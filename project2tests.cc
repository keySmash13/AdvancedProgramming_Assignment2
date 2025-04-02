// Copyright 2025 Abby Holdcraft
// Testing added methods/operators: !=, Add, Prepend, Append, Concat
#include<iostream>
using std::cout;
using std::endl;
using std::cin;
#include"dynamicarray.h"

int main() {
  DynamicArray a(10);
  for ( int i = 0; i < a.GetSize(); i++ )
    a[i] = 2*i;
  cout << "Here is a: " << a << endl;
  DynamicArray b = a;
  cout << "Here is b: " << b << endl;
  if ( b == a )
    cout << "Passed == test" << endl;
  else
    cout << "Failed == test" << endl;
  if ( b != a )
    cout << "Failed != test" << endl;
  else
    cout << "Passed != test" << endl;
  a.Concat(b);
  cout << "Here is a concatenated with b: " << a << endl;
  cout << "Adding tests:" <<endl;
  cout << "Original: " << b << endl;
  cout << "Adding 10 to end:" <<endl;
  b.Add(10);
  cout << b <<endl;
  cout << "Adding 20 at index 3:" <<endl;
  b.Add(20, 3);
  cout << b <<endl;
  cout << "Adding -30 to index -99 (default to end):" <<endl;
  b.Add(-30, -99);
  cout << b <<endl;
  cout << "Adding int b = 40 to index 99 (default to end):" <<endl;
  int add = 40;
  b.Add(add, 99);
  cout << b <<endl;
  cout << "Adding 45 to index 0:" <<endl;
  b.Add(45, 0);
  cout << b <<endl;
  cout << "Prepending 50:" <<endl;
  b.Prepend(50);
  cout << b <<endl;
  cout << "Prepending -60:" <<endl;
  b.Prepend(-60);
  cout << b <<endl;
  cout << "Appending 70:" <<endl;
  b.Append(70);
  cout << b <<endl;
  cout << "Appending -80:" <<endl;
  b.Append(-80);
  cout << b <<endl;
  cout << "Sorting asc" << endl;
  b.Sort();
  cout << b << endl;
  cout << "Sorting dsc" << endl;
  b.Sort(true);
  cout << b << endl;
  cout << "Removing duplicate 10s" << endl;
  b.RemoveDuplicates();
  cout << b << endl;

}
