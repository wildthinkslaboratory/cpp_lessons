#include <array>
#include <vector>

#include "utilities.h"
using namespace std;

// come back to these functions after reading main
vector<int> prefix_sums1(const vector<int>& input) {
  vector<int> temp(input.size());
  int running = 0;

  for (size_t i = 0; i < input.size(); ++i) {
    running += input[i];
    temp[i] = running;
  }

  return temp;
}

vector<int> prefix_sums2(const vector<int>& input) {
  vector<int> temp;
  temp.reserve(input.size());
  int running = 0;

  for (size_t i = 0; i < input.size(); ++i) {
    running += input[i];
    temp[i] = running;
  }

  return temp;
}

void prefix_sums3(const vector<int>& input, vector<int>& result) {
  int running = 0;

  for (size_t i = 0; i < input.size(); ++i) {
    running += input[i];
    result[i] = running;
  }
}

const int NUM = 100000;
const int ARRAY_SZ = 20;
int main() {
  // this looks like it is just allocating space for
  // ARRAY_SZ elements, but it is initilizing them
  // all to zero. That's why this is so slow.
  clock_t start = clock();
  for (size_t i = 0; i < NUM; i++) {
    vector<int> A(ARRAY_SZ);
  }
  cout << "vector<int>(ARRAY_SZ) allocation: " << get_elapsed_time(start)
       << endl;

  // this allocates uninitialized space.
  // vectors are always on the heap which is slower than on the stack.
  start = clock();
  for (size_t i = 0; i < NUM; i++) {
    vector<int> A;
    A.reserve(ARRAY_SZ);
  }
  cout << "vector reserve allocation: " << get_elapsed_time(start) << endl;

  // array is a thin wrapper around a c-style array
  // these are on the stack and fast to allocate, but if the
  // array is really big you'll get a segmentation fault
  start = clock();
  for (size_t i = 0; i < NUM; i++) {
    array<int, ARRAY_SZ> A;
  }
  cout << "array allocation: " << get_elapsed_time(start) << endl;

  // c-style array on stack allocation is super fast, but if the
  // array is really big you'll get a segmentation fault
  start = clock();
  for (size_t i = 0; i < NUM; i++) {
    int A[ARRAY_SZ];
  }
  cout << "c array allocation on stack: " << get_elapsed_time(start) << endl;

  // c-style on the heap is slightly more expensive. This is good
  // if you have a really large array
  start = clock();
  for (size_t i = 0; i < NUM; i++) {
    int* A = new int[ARRAY_SZ];
    delete[] A;
  }
  cout << "c array allocation on heap: " << get_elapsed_time(start) << endl
       << endl;
  ;

  // the best way to reduce allocation and initialization costs is to not
  // do them at all. Here are two versions of prefix_sums
  // one uses a locally allocated data structure. The other
  // reuses a buffer allocated once.
  vector<int> A = random_array(ARRAY_SZ, 1000);

  start = clock();
  for (size_t i = 0; i < NUM; i++) {
    vector<int> result = prefix_sums1(A);
  }
  cout << "prefix sum with reallocated temp: " << get_elapsed_time(start)
       << endl;

  start = clock();
  for (size_t i = 0; i < NUM; i++) {
    vector<int> result = prefix_sums2(A);
  }
  cout << "prefix sum with reallocated uninitialized temp: "
       << get_elapsed_time(start) << endl;

  vector<int> temp;
  temp.reserve(A.size());
  start = clock();
  for (size_t i = 0; i < NUM; i++) {
    prefix_sums3(A, temp);
  }
  cout << "prefix sum with reused temp: " << get_elapsed_time(start) << endl;

  return 0;
}