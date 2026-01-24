#include <array>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

// This function allows you to output a vector to standard out.
// input and output in c++ is through streams.
// an ostream is an output stream
// I typically put functions like this in a utilities.h file
// so I don't have to keep rewriting them.
inline ostream& operator<<(ostream& os, const vector<int>& v) {
  os << "[ ";
  for (int i = 0; i < v.size(); i++) os << v[i] << ' ';
  os << ']';
  return os;
}

const int ARRAY_SZ = 10000;

int main() {
  /*----------------------------- C style ---------------------------------*/

  int c1[4] = {1, 2, 3, 4};
  int c2[ARRAY_SZ];  // on the stack

  // NOTE: if you make the array larger, by adding a few 0's to ARRAY_SZ
  // You will get a segmentation fault. You can't put a really large array
  // on the stack. You will need to put it on the heap.

  // initialized on the heap
  int* c3 = new int[ARRAY_SZ];

  // adding elements
  clock_t start_cpu = std::clock();
  for (size_t i = 0; i < ARRAY_SZ; i++) c3[i] = i;
  clock_t end_cpu = std::clock();
  cout << "runtime for filling c style array: "
       << static_cast<double>(end_cpu - start_cpu) / CLOCKS_PER_SEC << endl;

  delete[] c3;  // clean up memory

  /*----------------------------- std array ---------------------------------*/
  array<int, ARRAY_SZ> a1;

  //   adding elements
  start_cpu = std::clock();
  for (size_t i = 0; i < ARRAY_SZ; i++) a1[i] = i;
  end_cpu = std::clock();
  cout << "runtime for filling array: "
       << static_cast<double>(end_cpu - start_cpu) / CLOCKS_PER_SEC << endl;

  /*----------------------------- std vector ---------------------------------*/

  // create an empty vector without specifying size
  vector<int> v1;
  start_cpu = std::clock();
  for (size_t i = 0; i < ARRAY_SZ; i++) v1.push_back(i);
  end_cpu = std::clock();
  cout << "runtime for filling vector: "
       << static_cast<double>(end_cpu - start_cpu) / CLOCKS_PER_SEC << endl;

  // create a vector and allocate space for it
  vector<int> v2(ARRAY_SZ);
  start_cpu = std::clock();
  for (size_t i = 0; i < ARRAY_SZ; i++) v2[i] = i;
  end_cpu = std::clock();
  cout << "runtime for filling preallocated vector: "
       << static_cast<double>(end_cpu - start_cpu) / CLOCKS_PER_SEC << endl;

  // other useful ways of initializing a vector
  vector<int> v3(10, 0);
  cout << v3 << endl;

  vector<int> v4 = {1, 2, 3, 4};  // initialize a vector with a given array
  cout << v4 << endl;

  return 0;
}