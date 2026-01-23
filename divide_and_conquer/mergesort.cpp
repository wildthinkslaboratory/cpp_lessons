#include <iostream>
#include <vector>

#include "utilities.h"
using namespace std;

vector<int> merge(const vector<int>& v1, const vector<int>& v2) {
  if (v1.size() == 0) return v2;
  if (v2.size() == 0) return v1;

  vector<int> v(v1.size() + v2.size());
  size_t i1 = 0, i2 = 0, i = 0;

  while (i < (v1.size() + v2.size())) {
    if (i2 >= v2.size()) {
      v[i] = v1[i1];
      i1++;
    } else if (i1 >= v1.size()) {
      v[i] = v2[i2];
      i2++;
    } else if (v1[i1] <= v2[i2]) {
      v[i] = v1[i1];
      i1++;
    } else {
      v[i] = v2[i2];
      i2++;
    }
    i++;
  }
  return v;
}

vector<int> mergesort(vector<int>& nums) {
  if (nums.size() > 1) {
    vector<int>::iterator mid = nums.begin() + nums.size() / 2;
    vector<int> slice_left(nums.begin(), mid);
    vector<int> slice_right(mid, nums.end());
    return merge(mergesort(slice_left), mergesort(slice_right));
  }
  return nums;
}

int main() {
  vector<int> A = random_array(100000, 100);

  clock_t start_cpu = std::clock();
  vector<int> sortedA = mergesort(A);
  clock_t end_cpu = std::clock();
  cout << "mergesort runtime: "
       << static_cast<double>(end_cpu - start_cpu) / CLOCKS_PER_SEC << endl;
  return 0;
}