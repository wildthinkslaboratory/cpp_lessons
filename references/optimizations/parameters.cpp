#include <vector>

#include "utilities.h"

using namespace std;

/*
  ------- pass by VALUE -------
  every time the function is called we make a copy
  of A and pass it to the function
*/
double average_pass_value(vector<int> A) {
  int sum = 0;
  for (size_t i = 0; i < A.size(); i++) sum += A[i];
  return sum / static_cast<double>(A.size());
}

/*
  ------- pass by REFERENCE -------
  we pass in a reference to the vector A.
  A reference is the address where A lives in memory.
  Adding the const keyword means that the function
  only has read access to A. If const is omitted
  the function is allowed to write to A creating lasting
  changes to A outside this function. It's always good
  to make a pass by reference const if you don't need
  write permissions. The compiler can sometimes use
  this information to do additional optimizations.
*/
double average_pass_ref(const vector<int>& A) {
  int sum = 0;
  for (size_t i = 0; i < A.size(); i++) sum += A[i];
  return sum / static_cast<double>(A.size());
}

int main() {
  vector<int> A = random_array(10000, 1000);

  clock_t start = clock();
  for (size_t i = 0; i < 10000; i++) {
    double avg = average_pass_value(A);
  }
  cout << "time for average pass by value: " << get_elapsed_time(start) << endl;

  start = clock();
  for (size_t i = 0; i < 10000; i++) {
    double avg = average_pass_ref(A);
  }
  cout << "time for average pass by reference: " << get_elapsed_time(start)
       << endl;
}