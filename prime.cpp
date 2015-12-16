#include <iostream>
#include <ctime>
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
  int start_s = clock();
  calcPrime(10000000);
  int end_s = clock();
  cout << (end_s - start_s) / double(CLOCKS_PER_SEC) * 1000 << endl;
}
