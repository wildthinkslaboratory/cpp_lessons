/*  LEET CODE 27 Remove Element   */

#include <iostream>
#include <vector>
using namespace std;
#include "../utilities.h"

class Solution {
 public:
  int removeElement(vector<int>& nums, int val) {
    // put your solution code here
    return 0;
  }
};

int main() {
  Solution s;

  // test case 1
  vector<int> l({3, 2, 2, 3});
  int val = 3;

  cout << "remove element " << val << " from " << l << endl;
  cout << s.removeElement(l, val) << endl;

  // test case 2
  l = {0, 1, 2, 2, 3, 0, 4, 2};
  val = 2;

  cout << "remove element " << val << " from " << l << endl;
  cout << s.removeElement(l, val) << endl;

  return 0;
}