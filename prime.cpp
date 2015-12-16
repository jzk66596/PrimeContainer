#include <iostream>
#include <sys/time.h>
#include <unistd.h>
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
//    if (i % 10 == 0) {
//      usleep(10);
//    }
    if (!check) {
      ++count;
    }
  }
}

int main() {
  // cout << "Start" << endl;
  // int start_s = clock();
  // calcPrime(10000000);
  // int end_s = clock();
  // cout << "End" << endl;
  // cout << "Time: " << (end_s - start_s) / double(CLOCKS_PER_SEC) * 1000 << endl;
  
  struct timeval start, end;
  gettimeofday(&start, NULL);
  long starttime = start.tv_sec * 1000000 + start.tv_usec;
  // cout << start.tv_sec << " " << start.tv_usec << endl;
  calcPrime(15000000);
  gettimeofday(&end, NULL);
  // cout << end.tv_sec << " " << end.tv_usec << endl;
  long endtime = end.tv_sec * 1000000 + end.tv_usec;
  float runtime = (end.tv_sec + (end.tv_usec * 1.0 / 1000000)) - (start.tv_sec + (start.tv_usec * 1.0 / 1000000));
  // cout << "Time: " << (end.tv_sec + (end.tv_usec * 1.0 / 1000000)) - (start.tv_sec + (start.tv_usec * 1.0 / 1000000)) << endl;
  cout << starttime << " " << endtime << " " << runtime << endl;
  return 0;
}
