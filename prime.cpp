#include <iostream>
#include <sys/time.h>
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
}

int main() {
  cout << "Start" << endl;
  // int start_s = clock();
  // calcPrime(10000000);
  // int end_s = clock();
  // cout << "End" << endl;
  // cout << "Time: " << (end_s - start_s) / double(CLOCKS_PER_SEC) * 1000 << endl;
  
  struct timeval start, end;
  gettimeofday(&start, NULL);
  cout << "Start: " << start.tv_sec << " " << start.tv_usec << endl;
  calcPrime(10000000);
  gettimeofday(&end, NULL);
  cout << "End: " << end.tv_sec << " " << end.tv_usec << endl;
  cout << "Time: " << (end.tv_sec + (end.tv_usec * 1.0 / 1000000)) - (start.tv_sec + (start.tv_usec * 1.0 / 1000000)) << endl;
}
