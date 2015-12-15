#include <iostream>
using namespace std;

void calcPrime(int N) {
  int count = 0;
  for (int i = 2; i <= N; ++i) {
    bool check = false;
    for (int j = 2; j * j <= i; ++j) {
      if (i % j == 0) {
        check = true;
        break;
      }
    }
    if (!check) {
      ++count;
    }
  }
  cout << count << endl;
}

int main() {
  calcPrime(10000000);
}
