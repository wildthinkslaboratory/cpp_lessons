#include <iostream>
#include <vector>
using namespace std;
#include "../utilities.h"

int main() {
  vector<int> A({0, 1, 2, 3, 4, 5, 6, 7, 8, 9});

  cout << "access vector through indexing" << endl;
  for (size_t i = 0; i < A.size(); i++) {
    cout << A[i] << endl;
  }

  // an iterator is just a nice interface to use pointers
  cout << endl << "access vector through iterators" << endl;
  for (vector<int>::iterator it = A.begin(); it != A.end(); it++) {
    cout << *it << endl;
  }

  return 0;
}