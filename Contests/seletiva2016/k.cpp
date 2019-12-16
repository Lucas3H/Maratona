#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  double prob = 1;
  int p;
  for (p = 1; prob > 0.5; p++) {
    prob *= (double)(n - p)/n;
  }
  cout << p << endl;
}
