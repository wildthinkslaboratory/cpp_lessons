#include <algorithm>
#include <iostream>
#include <random>
#include <string>
#include <vector>

#include "utilities.h"
using namespace std;

int selection(const vector<int>& S, const int& k) {
  int v = S[rand() % S.size()];
  vector<int> S_l, S_v, S_r;

  for (size_t i = 0; i < S.size(); i++) {
    if (S[i] < v) {
      S_l.push_back(S[i]);
    } else if (S[i] == v) {
      S_v.push_back(S[i]);
    } else {
      S_r.push_back(S[i]);
    }
  }

  if (k < S_l.size()) return selection(S_l, k);
  if (k >= (S_l.size() + S_v.size()))
    return selection(S_r, k - S_l.size() - S_v.size());

  return v;
}

int median(const vector<int>& A) { return selection(A, A.size() / 2); }
int main() {
  srand(time(0));

  vector<int> A = read_array("tests/case1.txt");
  cout << "array: " << A << endl;

  int m = median(A);
  cout << "median " << m << endl;

  sort(A.begin(), A.end());
  cout << "sorted array " << A << endl;
  return 0;
}