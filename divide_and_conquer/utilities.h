#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

// this function allows you to output a vector to standard out
// input and output in c++ is through streams
// and ostream is an output stream
inline ostream& operator<<(ostream& os, const vector<int>& v) {
  os << "[ ";
  for (int i = 0; i < v.size(); i++) os << v[i] << ' ';
  os << ']';
  return os;
}

vector<int> read_array(string filename) {
  vector<int> A;

  // read in the array as a single line of integers seperated by spaces
  ifstream in_stream(filename);
  string line;
  if (!in_stream.is_open()) {
    cerr << "Could not open file " << filename << endl;
  } else {
    getline(in_stream, line);
  }
  in_stream.close();

  stringstream ss(line);
  string word;

  while (ss >> word) {
    A.push_back(stoi(word));
  }

  return A;
}

inline vector<int> random_array(size_t sz, int max_val) {
  vector<int> A(sz);
  for (size_t i = 0; i < sz; i++) A[i] = rand() % max_val;
  return A;
}