#include <algorithm>
#include <array>
#include <iostream>
#include <vector>

#include "utilities.h"
using namespace std;

// got a speed up from passing in the buffer and having to
// always reallocate it.
void merge(vector<int>& A, int beg, int mid, int end, vector<int>& temp) {
  if (A[mid - 1] <= A[mid]) return;

  copy(A.begin() + beg, A.begin() + mid, temp.begin());
  int r = mid, l = 0, i = beg, l_max = mid - beg;

  while (l < l_max && r < end) {
    if (temp[l] <= A[r])
      A[i] = temp[l++];
    else
      A[i] = A[r++];
    i++;
  }

  while (l < l_max) {
    A[i] = temp[l++];
    i++;
  }

  return;
}

void mergesort(vector<int>& A, int beg, int end, vector<int>& temp) {
  if (end - beg <= 1) return;
  int mid = beg + (end - beg) / 2;
  mergesort(A, beg, mid, temp);
  mergesort(A, mid, end, temp);
  merge(A, beg, mid, end, temp);
}

int main() {
  // vector<int> A = {3, 4, 7, 8, 11, 12, 1, 2, 5, 6, 9, 10};
  // vector<int> A = {3, 4, 5, 7, 1, 2, 2, 6};
  // cout << A << endl;
  // merge(A, 0, 4, 8);
  // cout << A << endl;

  srand(time(0));
  vector<int> A = random_array(100000, 1000);
  vector<int> temp(A.size());
  // cout << A << endl;

  clock_t start_cpu = std::clock();
  mergesort(A, 0, A.size(), temp);
  cout << "mergesort runtime: " << get_elapsed_time(start_cpu) << endl;
  // cout << A << endl;
  return 0;
}